/*M///////////////////////////////////////////////////////////////////////////
// Copyright (c) 2014, sheng
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright notice,
//       this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright notice,
//       this list of conditions and the following disclaimer in the documentation
//       and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//M*/



#include "CurrentTime.h"
#include "IntToString.h"


/**
 * @brief  GetCurrentTime Get the local curretn time in string
 * @return The string which represent the loacl current time
 * @author sheng
 * @date   2014-08-21
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng       2014-08-21          0.1         build the function
 *
 */
std::string GetCurrentTime()
{
    // get the seconds since 00:00 hours, Jan 1, 1970 UTC
    time_t Time = time(NULL);


    // convert the Time to the local time
    tm* LocalTime = localtime(&Time);


    // convert the loacl time to a string
    std::string CurrentInString = ConvertTimeToString(LocalTime);


    return CurrentInString;
}




/**
 * @brief ConvertTimeToString Convert the local current time to a string
 * @param Time The local current time
 * @return A string which represents the local current time
 *
 * @author sheng
 * @date   2014-08-21
 * @version 0.1
 *
 * @history
 *     <author>       <date>         <version>        <description>
 *      sheng       2014-08-21          0.1         build the function
 *
 *
 */
std::string ConvertTimeToString(tm* Time)
{
    std::string Result;

    if (Time)
    {
        // add the year
        Result += IntToString(Time->tm_year + 1900) + "-";

        // add the month
        Result += IntToString(Time->tm_mon + 1) + "-";

        // add the day
        Result += IntToString(Time->tm_mday) + "_";

        // add the hour
        Result += IntToString(Time->tm_hour) + "-";

        // add the minutes
        Result += IntToString(Time->tm_min) + "-";

        // add the seconds
        Result += IntToString(Time->tm_sec) + ".log";
    }

    return Result;
}
