/********************************************************************
* Description: cmsdiag.hh
*
*   Derived from a work by Fred Proctor & Will Shackleford
*
* Author:
* License: LGPL Version 2
* System: Linux
*    
* Copyright (c) 2004 All rights reserved.
*
* Last change: 
********************************************************************/

#ifndef CMSDIAG_HH
#define CMSDIAG_HH

#include "cms.hh"
class LinkedList;

class CMS_DIAG_STATIC_PROC_INFO {
  public:
    char name[16];		// process name
    char host_sysinfo[32];
    long pid;			/* Process, Thread or Task Id. */
    double rcslib_ver;		/* Version of the rcslib used by this
				   component. */
};

class CMS_DIAG_PROC_INFO:public CMS_DIAG_STATIC_PROC_INFO {
  public:
    CMS_INTERNAL_ACCESS_TYPE access_type;	/* access type of last
						   operation */
    long msg_id;		/* id of the message written or at time of
				   read. */
    long msg_size;		/* size of the message written or at time of
				   read. */
    long msg_type;		/* id of the message written or at time of
				   read. */
    long number_of_accesses;
    long number_of_new_messages;
    double bytes_moved;
    double bytes_moved_across_socket;
    double last_access_time;
    double first_access_time;
    double max_difference;
    double min_difference;
};

class CMS_DIAG_HEADER {
  public:
    long last_writer;
    long last_reader;
};

class CMS_DIAGNOSTICS_INFO:public CMS_DIAG_HEADER {
  public:
    CMS_DIAGNOSTICS_INFO();
    virtual ~ CMS_DIAGNOSTICS_INFO();
    CMS_DIAG_PROC_INFO *last_writer_dpi;
    CMS_DIAG_PROC_INFO *last_reader_dpi;
    LinkedList *dpis;
};

extern double cmsdiag_timebias;
extern int cmsdiag_timebias_set;

#endif
