/***
  This file is part of bus1. See COPYING for details.

  bus1 is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  bus1 is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with bus1; If not, see <http://www.gnu.org/licenses/>.
***/

#include <c-rbtree.h>
#include <c-list.h>
#include "org.bus1/b1-peer.h"

struct B1Handle {
        unsigned long n_ref;

        B1Peer *holder;
        B1Node *node;
        uint64_t id;

        bool marked; /* used for duplicate detection */

        CRBNode rb;
};

struct B1Node {
        B1Peer *owner;
        B1Handle *handle;
        uint64_t id;

        bool live:1;
        bool persistent:1;

        CRBNode rb_nodes;
};

int b1_handle_acquire(B1Peer *peer, B1Handle **handlep, uint64_t handle_id);
int b1_handle_link(B1Handle *handle, uint64_t id);
B1Handle *b1_handle_lookup(B1Peer *peer, uint64_t id);

int b1_node_link(B1Node *node, uint64_t id);
B1Node *b1_node_lookup(B1Peer *peer, uint64_t id);
