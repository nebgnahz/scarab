/////////////////////////////////////////////////////////////////////
//                                                                 //
// file: acpASCIIHexFilter.h			                   //
//                                                                 //
/////////////////////////////////////////////////////////////////////
//                                                                 //
// description: Utility class for counting stream I/O.		   //
//                                                                 //
/////////////////////////////////////////////////////////////////////
//                                                                 //
// Copyright 1994-2008. Acroname Inc.                              //
//                                                                 //
// This software is the property of Acroname Inc.  Any             //
// distribution, sale, transmission, or re-use of this code is     //
// strictly forbidden except with permission from Acroname Inc.    //
//                                                                 //
// To the full extent allowed by law, Acroname Inc. also excludes  //
// for itself and its suppliers any liability, wheither based in   //
// contract or tort (including negligence), for direct,            //
// incidental, consequential, indirect, special, or punitive       //
// damages of any kind, or for loss of revenue or profits, loss of //
// business, loss of information or data, or other financial loss  //
// arising out of or in connection with this software, even if     //
// Acroname Inc. has been advised of the possibility of such       //
// damages.                                                        //
//                                                                 //
// Acroname Inc.                                                   //
// www.acroname.com                                                //
// 720-564-0373                                                    //
//                                                                 //
/////////////////////////////////////////////////////////////////////

#ifndef _acpASCIIHexFilter_H_
#define _acpASCIIHexFilter_H_

#include "aIO.h"

class acpASCIIHexFilter
{
  public:
  
			acpASCIIHexFilter(
			  aIOLib ioRef,
			  aStreamRef passthrough = NULL,
			  const int nMaxLine = 0);
			~acpASCIIHexFilter();

    aStreamRef 		getStream()
    			  { return m_stream; }

  private:
    static char		hex[16];
    static aErr 	getProc(
                          char* pData,
			  void* ref);

    static aErr 	putProc(
    			  char* pData,
			  void* ref);

    static aErr 	deleteProc(
    			  void* ref);

    aIOLib		m_ioRef;
    aStreamRef		m_stream;
    aStreamRef		m_passthrough;
    int			m_nMaxLine;
    int			m_nWidth;
};

#endif // _acpASCIIHexFilter_H_
