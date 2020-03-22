/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-2-Clause) */
#include <stdlib.h>

#include "dis.h"
#include "verbs.h"

#ifndef PCI_VENDOR_ID_DIS
#define PCI_VENDOR_ID_DIS 0x0
#endif


static const struct verbs_match_ent hca_table[] = {
	VERBS_DRIVER_ID(RDMA_DRIVER_UNKNOWN),
	//VERBS_NAME_MATCH("dis", NULL),
	//{},
};


static void dis_free_context(struct ibv_context *ibv_ctx);
static const struct verbs_context_ops dis_ctx_ops = {
	.free_context 	= dis_free_context,
    .query_device  	= dis_query_device,
	.query_port    	= dis_query_port,

	.alloc_pd      	= dis_alloc_pd,
	.dealloc_pd    	= dis_dealloc_pd,
	//.free_pd 		= dis_free_pd,

	.reg_mr        	= dis_reg_mr,
	.dereg_mr     	= dis_dereg_mr,

	.create_cq     	= dis_create_cq,
	.poll_cq       	= dis_poll_cq,
	//.req_notify_cq 	= dis_notify_cq,
	//.cq_event      	= dis_cq_event,
	//.resize_cq     	= dis_resize_cq,
	.destroy_cq    	= dis_destroy_cq,

	//.create_srq    	= dis_create_srq,
	//.modify_srq    	= dis_modify_srq,
	//.query_srq     	= dis_query_srq,
	//.destroy_srq   	= dis_destroy_srq,
	//.post_srq_recv 	= dis_post_srq_recv,

	.create_qp     	= dis_create_qp,
	.query_qp      	= dis_query_qp,
	.modify_qp     	= dis_modify_qp,
	.destroy_qp    	= dis_destroy_qp,
	
	.post_send     	= dis_post_send,
	.post_recv     	= dis_post_recv,

	.create_ah     	= dis_create_ah,
	.destroy_ah    	= dis_destroy_ah,
};

static struct verbs_context *dis_alloc_context(struct ibv_device *ibv_dev, 
												int cmd_fd, 
												void *private_data)
{
	struct dis_context *ctx;
	struct ibv_get_context cmd;
	struct ib_uverbs_get_context_resp get_ctx_resp;

	ctx = verbs_init_and_alloc_context(ibv_dev, cmd_fd, ctx, ibv_ctx, 
										RDMA_DRIVER_UNKNOWN);

	if (!ctx) {
		return NULL;
	}

	if (ibv_cmd_get_context(&ctx->ibv_ctx,
							&cmd,
							sizeof(struct ibv_get_context), 
							&get_ctx_resp,
							sizeof(struct ib_uverbs_get_context_resp))) {
		verbs_uninit_context(&ctx->ibv_ctx);
		free(ctx);
	}

	verbs_set_ops(&ctx->ibv_ctx, &dis_ctx_ops);
	return &ctx->ibv_ctx;
}

static void dis_free_context(struct ibv_context *ibv_ctx)
{
	struct dis_context *ctx = to_dis_ctx(ibv_ctx);

	verbs_uninit_context(&ctx->ibv_ctx);
	free(ctx);
}

static struct verbs_device *dis_device_alloc(struct verbs_sysfs_dev *sysfs_dev)
{
	struct dis_device *dev;

	dev = malloc(sizeof(struct dis_device));
	if (!dev) {
		return NULL;
	}

	return &dev->ibv_dev;
}

static void dis_uninit_device(struct verbs_device *verbs_dev)
{
	struct dis_device *dev = to_dis_dev(&verbs_dev->device);

	free(dev);
}

static const struct verbs_device_ops dis_device_ops = {
	.name 					= "dis",
	.match_min_abi_version 	= DIS_ABI_VERSION,
	.match_max_abi_version 	= DIS_ABI_VERSION,
	.match_table 			= hca_table,
	.alloc_device 			= dis_device_alloc,
	.uninit_device  		= dis_uninit_device,
	.alloc_context 			= dis_alloc_context,
};
PROVIDER_DRIVER(dis, dis_device_ops);
