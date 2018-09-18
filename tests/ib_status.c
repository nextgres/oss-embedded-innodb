/***********************************************************************
Copyright (c) 2009 Innobase Oy. All rights reserved.
Copyright (c) 2009 Oracle. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

************************************************************************/
#include <stdio.h>
#include <assert.h>

#include "innodb.h"

#include "test0aux.h"

void
get_all()
{
	static const char*	var_names[] = {
		/* IO system related */
		"read_req_pending",
		"write_req_pending",
		"fsync_req_pending",
		"write_req_done",
		"read_req_done",
		"fsync_req_done",
		"bytes_total_written",
		"bytes_total_read",

		/* Buffer pool related */
		"buffer_pool_current_size",
		"buffer_pool_data_pages",
		"buffer_pool_dirty_pages",
		"buffer_pool_misc_pages",
		"buffer_pool_free_pages",
		"buffer_pool_read_reqs",
		"buffer_pool_reads",
		"buffer_pool_waited_for_free",
		"buffer_pool_pages_flushed",
		"buffer_pool_write_reqs",
		"buffer_pool_total_pages",
		"buffer_pool_pages_read",
		"buffer_pool_pages_written",

		/* Double write buffer related */
		"double_write_pages_written",
		"double_write_invoked",

		/* Log related */
		"log_buffer_slot_waits",
		"log_write_reqs",
		"log_write_flush_count",
		"log_bytes_written",
		"log_fsync_req_done",
		"log_write_req_pending",
		"log_fsync_req_pending",

		/* Lock related */
		"lock_row_waits",
		"lock_row_waiting",
		"lock_total_wait_time_in_secs",
		"lock_wait_time_avg_in_secs",
		"lock_max_wait_time_in_secs",

		/* Row operations */
		"row_total_read",
		"row_total_inserted",
		"row_total_updated",
		"row_total_deleted",

		/* Miscellaneous */
		"page_size",
		"have_atomic_builtins",
		NULL
	};
	
	const char**	ptr;
	ib_i64_t	val;

	for (ptr = var_names; *ptr ; ++ptr) {
		ib_err_t	err;

		err = ib_status_get_i64(*ptr, &val);
		assert(err == DB_SUCCESS);

		printf("%s: %d\n", *ptr, (int) val);
	}
}

int
main(int argc, char** argv)
{
	ib_err_t	err;

	err = ib_init();
	assert(err == DB_SUCCESS);

	test_configure();

	err = ib_startup("barracuda");
	assert(err == DB_SUCCESS);

	get_all();

	err = ib_shutdown(IB_SHUTDOWN_NORMAL);
	assert(err == DB_SUCCESS);

	return(0);
}
