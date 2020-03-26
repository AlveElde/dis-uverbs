/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-2-Clause) */
#ifndef __DIS_VERBS_H__
#define __DIS_VERBS_H__

#include <infiniband/verbs.h>
#include <infiniband/driver.h>

struct dis_device {
    struct verbs_device ibv_dev;
};

struct dis_context {
    struct verbs_context ibv_ctx;
};


static inline struct dis_context *to_dis_ctx(struct ibv_context *ibv_ctx)
{
    return container_of(ibv_ctx, struct dis_context, ibv_ctx.context);
}

static inline struct dis_device *to_dis_dev(struct ibv_device *ibv_dev)
{
    return container_of(ibv_dev, struct dis_device, ibv_dev.device);
}


// Device verbs.
int dis_query_device(struct ibv_context *ibv_ctx,
                        struct ibv_device_attr *attr);         
int dis_query_port(struct ibv_context *ibv_ctx,
                    uint8_t port,
                    struct ibv_port_attr *attr);

// Protection Domain verbs.
struct ibv_pd *dis_alloc_pd(struct ibv_context *ibv_ctx);
int dis_dealloc_pd(struct ibv_pd *ibv_pd);             

// Memory Region verbs.
struct ibv_mr *dis_reg_mr(struct ibv_pd *ibv_pd, 
                            void *buf, 
                            size_t len, 
                            uint64_t hca_va, 
                            int ibv_access_flags);
int dis_dereg_mr(struct verbs_mr *mr);

// Completion Queue verbs.
struct ibv_cq *dis_create_cq(struct ibv_context *ibv_ctx, 
                                int cqe_max, 
                                struct ibv_comp_channel *ibv_comp_ch, 
                                int vec);
int dis_poll_cq(struct ibv_cq *ibv_cq, int num_wc, struct ibv_wc *ibv_wc);
//int dis_notify_cq();
//int dis_cq_event();
//int dis_resize_cq();
int dis_destroy_cq(struct ibv_cq *ibv_cq);

// Shared Receive Queue verbs.
//struct ibv_srq *dis_create_srq();
//int dis_modify_srq();
//int dis_query_srq();
//int dis_resize_srq();
//int dis_destroy_srq();
//int dis_post_srq_recv();

// Queue pair verbs.
struct ibv_qp *dis_create_qp(struct ibv_pd *ibv_pd,
                                struct ibv_qp_init_attr *init_attr);
int dis_query_qp(struct ibv_qp *ibv_qp, 
                    struct ibv_qp_attr *attr, 
                    int attr_mask, 
                    struct ibv_qp_init_attr *init_attr);
int dis_modify_qp(struct ibv_qp *ibv_qp, 
                    struct ibv_qp_attr *attr, 
                    int attr_mask);
int dis_destroy_qp(struct ibv_qp *ibv_qp);

// Posting verbs.
int dis_post_send(struct ibv_qp *ibv_qp, 
                    struct ibv_send_wr *send_wr, 
                    struct ibv_send_wr **bad_wr);
int dis_post_recv(struct ibv_qp *ibv_qp, 
                    struct ibv_recv_wr *recv_wr,
                    struct ibv_recv_wr **bad_wr);

// Address Handle verbs.
struct ibv_ah *dis_create_ah(struct ibv_pd *ibv_pd, struct ibv_ah_attr *attr);
int dis_destroy_ah(struct ibv_ah *ibv_ah);

#endif /* __DIS_VERBS_H__ */