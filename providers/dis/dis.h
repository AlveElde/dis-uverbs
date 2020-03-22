/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR BSD-2-Clause) */
#include <infiniband/driver.h>
#include <infiniband/verbs.h>

#include "dis-abi.h"


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