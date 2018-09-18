/*****************************************************************************

Copyright (c) 1996, 2009, Innobase Oy. All Rights Reserved.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

*****************************************************************************/

/**************************************************//**
@file include/db0err.h
Global error codes for the database

Created 5/24/1996 Heikki Tuuri
*******************************************************/

#ifndef db0err_h
#define db0err_h

/* API_BEGIN_INCLUDE */

/** InnoDB error codes. Most of the error codes are internal to the engine
and will not be seen by user applications. The partial error codes reflect
the sub-state of an operation within InnoDB. Some of the error codes are
deprecated and are no longer used. */
enum db_err {
	DB_SUCCESS = 10,		/*!< A successult result */

	/* The following are error codes */
	DB_ERROR,			/*!< This is a generic error code. It
					is used to classify error conditions
					that can't be represented by other
					codes */

	DB_INTERRUPTED,			/*!< An operation was interrupted by
					a user. */

	DB_OUT_OF_MEMORY,		/*!< Operation caused an out of memory
					error. Within InnoDB core code this is
					normally a fatal error */

	DB_OUT_OF_FILE_SPACE,		/*!< The operating system returned
					an out of file space error when trying
					to do an IO operation. */

	DB_LOCK_WAIT,			/*!< A lock request by transaction
					resulted in a lock wait. The thread
					is suspended internally by InnoDB and
					is put on a lock wait queue. */

	DB_DEADLOCK,			/*!< A lock request by a transaction
					resulted in a deadlock. The transaction
					was rolled back */

	DB_ROLLBACK,			/*!< Not used */

	DB_DUPLICATE_KEY,		/*!< A record insert or update violates
					a unique contraint. */

	DB_QUE_THR_SUSPENDED,		/*!< A query thread should be in state
					suspended but is trying to acquire a
					lock. Currently this is treated as a
					hard error and a violation of an
					invariant. */

	DB_MISSING_HISTORY,		/*!< Required history data has been
					deleted due to lack of space in
					rollback segment */

	DB_CLUSTER_NOT_FOUND = 30,	/*!< This error is not used */

	DB_TABLE_NOT_FOUND,		/*!< The table could not be found */

	DB_MUST_GET_MORE_FILE_SPACE,	/*!< The database has to be stopped
					and restarted with more file space */

	DB_TABLE_IS_BEING_USED,		/*!< The user is trying to create a
					table in the InnoDB data dictionary but
					a table with that name already exists */

	DB_TOO_BIG_RECORD,		/*!< A record in an index would not fit
					on a compressed page, or it would
					become bigger than 1/2 free space in
					an uncompressed page frame */

	DB_LOCK_WAIT_TIMEOUT,		/*!< Lock wait lasted too long */

	DB_NO_REFERENCED_ROW,		/*!< Referenced key value not found
					for a foreign key in an insert or
					update of a row */

	DB_ROW_IS_REFERENCED,		/*!< Cannot delete or update a row
					because it contains a key value
					which is referenced */

	DB_CANNOT_ADD_CONSTRAINT,	/*!< Adding a foreign key constraint
					to a table failed */

	DB_CORRUPTION,			/*!< Data structure corruption
					noticed */

	DB_COL_APPEARS_TWICE_IN_INDEX,	/*!< InnoDB cannot handle an index
					where same column appears twice */

	DB_CANNOT_DROP_CONSTRAINT,	/*!< Dropping a foreign key constraint
					from a table failed */

	DB_NO_SAVEPOINT,		/*!< No savepoint exists with the given
					name */

	DB_TABLESPACE_ALREADY_EXISTS,	/*!< We cannot create a new single-table
					tablespace because a file of the same
					name already exists */

	DB_TABLESPACE_DELETED,		/*!< Tablespace does not exist or is
					being dropped right now */

	DB_LOCK_TABLE_FULL,		/*!< Lock structs have exhausted the
					buffer pool (for big transactions,
					InnoDB stores the lock structs in the
					buffer pool) */

	DB_FOREIGN_DUPLICATE_KEY,	/*!< Foreign key constraints
					activated but the operation would
					lead to a duplicate key in some
					table */

	DB_TOO_MANY_CONCURRENT_TRXS,	/*!< When InnoDB runs out of the
					preconfigured undo slots, this can
					only happen when there are too many
					concurrent transactions */

	DB_UNSUPPORTED,			/*!< When InnoDB sees any artefact or
					a feature that it can't recoginize or
					work with e.g., FT indexes created by
					a later version of the engine. */

	DB_PRIMARY_KEY_IS_NULL,		/*!< A column in the PRIMARY KEY
					was found to be NULL */

	DB_FATAL,			/*!< The application should clean up
					and quite ASAP. Fatal error, InnoDB
					cannot continue operation without
					risking database corruption. */

	/* The following are partial failure codes */
	DB_FAIL = 1000,			/*!< Partial failure code. */

	DB_OVERFLOW,			/*!< If an update or insert of a record
					doesn't fit in a Btree page */

	DB_UNDERFLOW,			/*!< If an update or delete of a
					record causes a Btree page to be below
					a minimum threshold */

	DB_STRONG_FAIL,			/*!< Failure to insert a secondary
					index entry to the insert buffer */

	DB_ZIP_OVERFLOW,		/*!< Failure trying to compress
					a page */

	DB_RECORD_NOT_FOUND = 1500,	/*!< Record not found */

	DB_END_OF_INDEX,		/*!< A cursor operation or search
					operation scanned to the end of the
					index. */

	/* The following are API only error codes. */
	DB_SCHEMA_ERROR = 2000,		/*!< Generic schema error */

	DB_DATA_MISMATCH,		/*!< Column update or read failed
					because the types mismatch */

	DB_SCHEMA_NOT_LOCKED,		/*!< If an API function expects the
					schema to be locked in exclusive mode
					and if it's not then that API function
					will return this error code */

	DB_NOT_FOUND,			/*!< Generic error code for "Not found"
					type of errors */

	DB_READONLY,			/*!< Generic error code for "Readonly"
					type of errors */

	DB_INVALID_INPUT,		/*!< Generic error code for "Invalid
					input" type of errors */
};
/* API_END_INCLUDE */
#endif
