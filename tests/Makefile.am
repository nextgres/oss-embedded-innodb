# Copyright (C) 2008 Oracle/Innobase Oy
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# Process this file with automake to create Makefile.in
#
noinst_PROGRAMS		= ib_cfg \
			  ib_compressed \
			  ib_cursor \
			  ib_drop \
			  ib_ddl \
			  ib_dict \
			  ib_index \
			  ib_logger \
			  ib_mt_drv \
			  ib_mt_stress \
			  ib_recover \
			  ib_search \
			  ib_shutdown \
			  ib_status \
			  ib_tablename \
			  ib_test1 \
			  ib_test2 \
			  ib_test3 \
			  ib_test5 \
			  ib_types \
			  ib_update \
			  ib_zip
if HAVE_PTHREAD_BARRIER
noinst_PROGRAMS		+= ib_deadlock \
			  ib_perf1
endif

embeddeddir		= $(datadir)/$(INSTDIR)/examples
embedded_DATA		= \
			  Makefile.examples \
			  README \
			  ib_cfg.c \
			  ib_compressed.c \
			  ib_cursor.c \
			  ib_index.c \
			  ib_logger.c \
			  ib_mt_stress.c \
			  ib_search.c \
			  ib_status.c \
			  ib_test1.c \
			  ib_test2.c \
			  ib_test3.c \
			  ib_test5.c \
			  ib_types.c \
			  test0aux.c \
			  test0aux.h \
			  ib_update.c
if HAVE_PTHREAD_BARRIER
embedded_DATA		+= ib_perf1.c
endif

noinst_HEADERS 		= ib_mt_base.h \
			  ib_mt_drv.h \
			  test0aux.h

# We want these in the dist tarball
EXTRA_DIST		= \
			  CMakeLists.txt \
			  CMakeLists.examples \
			  Makefile.examples \
			  README

ib_cfg_SOURCES		= test0aux.c ib_cfg.c
ib_compressed_SOURCES	= test0aux.c ib_compressed.c
ib_ddl_SOURCES		= test0aux.c ib_ddl.c
if HAVE_PTHREAD_BARRIER
ib_deadlock_SOURCES	= test0aux.c ib_deadlock.c
endif
ib_drop_SOURCES		= test0aux.c ib_drop.c
ib_dict_SOURCES		= test0aux.c ib_dict.c
ib_index_SOURCES	= test0aux.c ib_index.c
ib_test1_SOURCES	= test0aux.c ib_test1.c
ib_tablename_SOURCES	= test0aux.c ib_tablename.c
ib_test2_SOURCES	= test0aux.c ib_test2.c
ib_test3_SOURCES	= test0aux.c ib_test3.c
ib_test5_SOURCES	= test0aux.c ib_test5.c
ib_mt_stress_SOURCES	= test0aux.c ib_mt_stress.c
ib_mt_drv_SOURCES	= test0aux.c ib_mt_drv.c ib_mt_base.c \
			  ib_mt_t1.c ib_mt_t2.c
if HAVE_PTHREAD_BARRIER
ib_perf1_SOURCES	= test0aux.c ib_perf1.c
endif
ib_recover_SOURCES	= test0aux.c ib_recover.c
ib_search_SOURCES	= test0aux.c ib_search.c
ib_shutdown_SOURCES	= test0aux.c ib_shutdown.c
ib_status_SOURCES	= test0aux.c ib_status.c
ib_types_SOURCES	= test0aux.c ib_types.c
ib_cursor_SOURCES	= test0aux.c ib_cursor.c
ib_logger_SOURCES	= test0aux.c ib_logger.c
ib_update_SOURCES	= test0aux.c ib_update.c
ib_zip_SOURCES		= test0aux.c ib_zip.c

INCLUDES		= -I@top_srcdir@/include -I@top_srcdir@/tests

LDADD			= @top_srcdir@/libinnodb.la -lpthread  -lm
