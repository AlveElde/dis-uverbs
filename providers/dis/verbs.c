/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-2-Clause) */
#include <stdlib.h>
#include <stdio.h>

#include "verbs.h"
#include "common.h"
#include "dis-abi.h"

int dis_query_device(struct ibv_context *ibv_ctx, struct ibv_device_attr *attr)
{
    int ret;
    size_t cmd_size;
    uint64_t raw_fw_ver;
    struct ibv_query_device cmd;
    printf_debug(DIS_STATUS_START);

    cmd_size = sizeof(struct ibv_query_device);
    memset(&cmd, 0, cmd_size);

    ret = ibv_cmd_query_device(ibv_ctx, attr, &raw_fw_ver, &cmd, cmd_size);
    if (ret) {
        printf_debug(DIS_STATUS_FAIL);
        return ret;
    }

    printf_debug(DIS_STATUS_COMPLETE);
    return 0;
}

int dis_query_port(struct ibv_context *ibv_ctx, 
                    uint8_t port, 
                    struct ibv_port_attr *attr)
{
    int ret;
    size_t cmd_size;
    struct ibv_query_port cmd;
    printf_debug(DIS_STATUS_START);

    cmd_size = sizeof(struct ibv_query_port);
    memset(&cmd, 0, cmd_size);

    ret = ibv_cmd_query_port(ibv_ctx, port, attr, &cmd, cmd_size);
    if (ret) {
        printf_debug(DIS_STATUS_FAIL);
        return ret;
    }

    printf_debug(DIS_STATUS_COMPLETE);
    return 0;
}

struct ibv_pd *dis_alloc_pd(struct ibv_context *ibv_ctx)
{
    int ret;
    size_t cmd_size, pd_size, resp_size;
    struct ibv_pd *ibv_pd;
    struct ibv_alloc_pd cmd;
    struct ib_uverbs_alloc_pd_resp resp;
    printf_debug(DIS_STATUS_START);

    pd_size     = sizeof(struct ibv_pd);
    resp_size	= sizeof(struct ib_uverbs_alloc_pd_resp);
    cmd_size    = sizeof(struct ibv_query_port);
    memset(&cmd, 0, cmd_size);
	memset(&resp, 0, resp_size);

    ibv_pd = malloc(pd_size);
    if (!ibv_pd) {
        printf_debug(DIS_STATUS_FAIL);
        return NULL;
    }

    ret = ibv_cmd_alloc_pd(ibv_ctx, 
                            ibv_pd,
                            &cmd, 
                            cmd_size, 
                            &resp, 
                        	resp_size);
    if (ret) {
        printf_debug(DIS_STATUS_FAIL);
		free(ibv_pd);
        return NULL;;
    }
	ibv_pd->context = ibv_ctx;
    printf_debug(DIS_STATUS_COMPLETE);
    return ibv_pd;
}

int dis_dealloc_pd(struct ibv_pd *ibv_pd)
{
    int ret;
    printf_debug(DIS_STATUS_START);

    ret = ibv_cmd_dealloc_pd(ibv_pd);
    if (ret) {
        printf_debug(DIS_STATUS_FAIL);
        return ret;
    }

    free(ibv_pd);

    printf_debug(DIS_STATUS_COMPLETE);
    return 0;
}

struct ibv_mr *dis_reg_mr(struct ibv_pd *ibv_pd, 
                            void *buf, 
                            size_t len, 
                            uint64_t hca_va, 
                            int ibv_access_flags)
{
    errno = ENOSYS;
    return NULL;
}

int dis_dereg_mr(struct verbs_mr *mr)
{
    return ENOSYS;
}

struct ibv_cq *dis_create_cq(struct ibv_context *ibv_ctx, 
                                int cqe_max, 
                                struct ibv_comp_channel *ibv_comp_ch, 
                                int vec)
{
    int ret;
    size_t cmd_size, cq_size, resp_size;
    struct ibv_cq *ibv_cq;
    struct ibv_create_cq cmd;
    struct ib_uverbs_create_cq_resp resp;
    printf_debug(DIS_STATUS_START);

    cq_size     = sizeof(struct ibv_cq);
    resp_size	= sizeof(struct ib_uverbs_create_cq_resp);
    cmd_size    = sizeof(struct ibv_create_cq);
    memset(&cmd, 0, cmd_size);
    memset(&resp, 0, resp_size);

	ibv_cq = malloc(cq_size);
    if (!ibv_cq) {
        printf_debug(DIS_STATUS_FAIL);
        return NULL;
    }
    
    ret = ibv_cmd_create_cq(ibv_ctx, 
                            cqe_max, 
                            ibv_comp_ch, 
                            vec, 
							ibv_cq, 
                            &cmd, 
                            cmd_size, 
                            &resp, 
                            resp_size);
	if (ret) {
        printf_debug(DIS_STATUS_FAIL);
		free(ibv_cq);
        return NULL;
    }

	printf_debug(DIS_STATUS_COMPLETE);
    return ibv_cq;
}

int dis_poll_cq(struct ibv_cq *ibv_cq, int nwc, struct ibv_wc *wc)
{
    return ENOSYS;
}

int dis_destroy_cq(struct ibv_cq *ibv_cq)
{
	int ret;
    printf_debug(DIS_STATUS_START);

    ret = ibv_cmd_destroy_cq(ibv_cq);
    if (ret) {
        printf_debug(DIS_STATUS_FAIL);
        return ret;
    }

    free(ibv_cq);

    printf_debug(DIS_STATUS_COMPLETE);
    return 0;
}

struct ibv_qp *dis_create_qp(struct ibv_pd *ibv_pd, 
                                struct ibv_qp_init_attr *init_attr)
{
    int ret;
    size_t cmd_size, qp_size, resp_size;
    struct ibv_qp *ibv_qp;
    struct ibv_create_qp cmd;
    struct ib_uverbs_create_qp_resp resp;
    printf_debug(DIS_STATUS_START);

    qp_size     = sizeof(struct ibv_qp);
    resp_size	= sizeof(struct ib_uverbs_create_qp_resp);
    cmd_size    = sizeof(struct ibv_create_qp);
    memset(&cmd, 0, cmd_size);
    memset(&resp, 0, resp_size);

	ibv_qp = malloc(qp_size);
    if (!ibv_qp) {
        printf_debug(DIS_STATUS_FAIL);
        return NULL;
    }

	ret = ibv_cmd_create_qp(ibv_pd, 
							ibv_qp, 
							init_attr, 
							&cmd, 
							cmd_size, 
							&resp, 
							resp_size);
	if (ret) {
        printf_debug(DIS_STATUS_FAIL);
		free(ibv_qp);
        return NULL;
    }

	printf_debug(DIS_STATUS_COMPLETE);
	return ibv_qp;
}

int dis_query_qp(struct ibv_qp *ibv_qp, 
                    struct ibv_qp_attr *attr, 
                    int attr_mask, 
                    struct ibv_qp_init_attr *init_attr)
{
    return ENOSYS;
}

int dis_modify_qp(struct ibv_qp *ibv_qp, 
                    struct ibv_qp_attr *attr, 
                    int attr_mask)
{
    int ret;
	size_t cmd_size;
	struct ibv_modify_qp cmd;
	printf_debug(DIS_STATUS_START);

	cmd_size = sizeof(struct ibv_modify_qp);
	memset(&cmd, 0, cmd_size);

	printf_debug("Attr mask: %d\n", attr_mask);
	
	ret = ibv_cmd_modify_qp(ibv_qp, attr, attr_mask, &cmd, cmd_size);
	if (ret) {
		printf_debug(DIS_STATUS_FAIL);
		return ret;
	}

	printf_debug(DIS_STATUS_COMPLETE);
	return 0;
}

int dis_destroy_qp(struct ibv_qp *ibv_qp)
{
    int ret;
    printf_debug(DIS_STATUS_START);

    ret = ibv_cmd_destroy_qp(ibv_qp);
    if (ret) {
        printf_debug(DIS_STATUS_FAIL);
        return ret;
    }

    free(ibv_qp);

    printf_debug(DIS_STATUS_COMPLETE);
    return 0;
}

int dis_post_send(struct ibv_qp *ibv_qp, 
                    struct ibv_send_wr *send_wr, 
                    struct ibv_send_wr **bad_wr)
{
    return ENOSYS;
}

int dis_post_recv(struct ibv_qp *ibv_qp, 
                    struct ibv_recv_wr *recv_wr, 
                    struct ibv_recv_wr **bad_wr)
{
    return ENOSYS;
}

struct ibv_ah *dis_create_ah(struct ibv_pd *ibv_pd, struct ibv_ah_attr *attr)
{
    errno = ENOSYS;
    return NULL;
}

int dis_destroy_ah(struct ibv_ah *ibv_ah)
{
    return ENOSYS;
}