/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-2-Clause) */
#include "verbs.h"

int dis_query_device(struct ibv_context *ibv_ctx, struct ibv_device_attr *attr)
{
    // attr->fw_ver            = 0;

    // attr->node_guid         = 0;
    // attr->sys_image_guid    = 0;
    // attr->max_mr_size       = 0;
    // attr->page_size_cap     = 0;
    // attr->vendor_id         = 0;
    // attr->vendor_part_id    = 0;
    // attr->hw_ver            = 0;
    // attr->max_qp            = 0;
    // attr->max_qp_wr         = 0;
    // attr->device_cap_flags  = 0;
    // attr->max_sge           = 0;
    // attr->max_sge_rd	    = 0;
	// attr->max_cq		    = 0;
	// attr->max_cqe	        = 0;
	// attr->max_mr	    	= 0;
	// attr->max_pd		    = 0;
	// attr->max_qp_rd_atom    = 0;
	// attr->max_ee_rd_atom	= 0;
	// attr->max_res_rd_atom	= 0;
	// attr->max_qp_init_rd_atom	    = 0;
	// attr->max_ee_init_rd_atom	    = 0;
	// attr->atomic_cap		= 0;
	// attr->max_ee			= 0;
	// attr->max_rdd			= 0;
	// attr->max_mw			= 0;
	// attr->max_raw_ipv6_qp	= 0;
	// attr->max_raw_ethy_qp	= 0;
	// attr->max_mcast_grp		= 0;
	// attr->max_mcast_qp_attach       = 0;
	// attr->max_total_mcast_qp_attach	= 0;
	// attr->max_ah			= 0;
	// attr->max_fmr			= 0;
	// attr->max_map_per_fmr	= 0;
	// attr->max_srq			= 0;
	// attr->max_srq_wr		= 0;
	// attr->max_srq_sge		= 0;
	// attr->max_pkeys			= 0;
	// attr->local_ca_ack_delay        = 0;
	// attr->phys_port_cnt		= 0;
	return ENOSYS;
}

int dis_query_port(struct ibv_context *ibv_ctx, 
					uint8_t port, 
					struct ibv_port_attr *attr)
{
	return ENOSYS;
}

struct ibv_pd *dis_alloc_pd(struct ibv_context *ibv_ctx)
{
	errno = ENOSYS;
	return NULL;
}

int dis_dealloc_pd(struct ibv_pd *ibv_pd)
{
	return ENOSYS;
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
	errno = ENOSYS;
	return NULL;
}

int dis_poll_cq(struct ibv_cq *ibvcq, int nwc, struct ibv_wc *wc)
{
	return ENOSYS;
}

int dis_destroy_cq(struct ibv_cq *ibvcq)
{
	return ENOSYS;
}

struct ibv_qp *dis_create_qp(struct ibv_pd *ibv_pd, 
								struct ibv_qp_init_attr *init_attr)
{
	errno = ENOSYS;
	return NULL;
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
					int ibv_qp_attr_mask)
{
	return ENOSYS;
}

int dis_destroy_qp(struct ibv_qp *ibv_qp)
{
	return ENOSYS;
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