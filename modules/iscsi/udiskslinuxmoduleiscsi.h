/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2020 Tomas Bzatek <tbzatek@redhat.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __UDISKS_LINUX_MODULE_ISCSI_H__
#define __UDISKS_LINUX_MODULE_ISCSI_H__

#include <src/udisksdaemontypes.h>
#include <src/udisksmodule.h>
#include "udisksiscsitypes.h"

G_BEGIN_DECLS

#define UDISKS_TYPE_LINUX_MODULE_ISCSI            (udisks_linux_module_iscsi_get_type ())
#define UDISKS_LINUX_MODULE_ISCSI(o)              (G_TYPE_CHECK_INSTANCE_CAST ((o), UDISKS_TYPE_LINUX_MODULE_ISCSI, UDisksLinuxModuleISCSI))
#define UDISKS_IS_LINUX_MODULE_ISCSI(o)           (G_TYPE_CHECK_INSTANCE_TYPE ((o), UDISKS_TYPE_LINUX_MODULE_ISCSI))

GType                    udisks_linux_module_iscsi_get_type   (void) G_GNUC_CONST;

/* Corresponds with the UDisksModuleIDFunc type */
G_MODULE_EXPORT
gchar                   *udisks_module_id                     (void);

G_MODULE_EXPORT
UDisksModule            *udisks_module_iscsi_new              (UDisksDaemon  *daemon,
                                                               GCancellable  *cancellable,
                                                               GError       **error);

struct libiscsi_context *udisks_linux_module_iscsi_get_libiscsi_context    (UDisksLinuxModuleISCSI *module);
void                     udisks_linux_module_iscsi_lock_libiscsi_context   (UDisksLinuxModuleISCSI *module);
void                     udisks_linux_module_iscsi_unlock_libiscsi_context (UDisksLinuxModuleISCSI *module);

G_END_DECLS

#endif /* __UDISKS_LINUX_MODULE_ISCSI_H__ */
