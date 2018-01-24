//
// Created by carlos on 19-10-17.
//

#ifndef SUCHAI_FLIGHT_SOFTWARE_MAIN_H
#define SUCHAI_FLIGHT_SOFTWARE_MAIN_H

#include "config.h"
#include <stdio.h>
#include <signal.h>

#ifdef AVR32
    #include "asf.h"
    #include "util.h"
    #include <time.h>
    #include <avr32/io.h>
    #include "intc.h"
    #include "board.h"
    #include "compiler.h"
    #include "rtc.h"
    #include "usart.h"
    #include "pm.h"

/**
 *
 * Makes an interruption to update the system time
 *
 * @return interruption
 */
__attribute__((__interrupt__)) void rtc_irq(void);
#endif


/* OS includes */
#include "osThread.h"
#include "osScheduler.h"
#include "osQueue.h"
#include "osSemphr.h"
#include "os.h"

/* system includes */
#include "globals.h"
#include "utils.h"
#include "repoData.h"
#include "repoCommand.h"

#ifdef LINUX
    #include <csp/csp.h>
    #include <csp/interfaces/csp_if_zmqhub.h>
#endif

/* Task includes */
#if SCH_TEST_ENABLED
    #include "taskTest.h"
#endif
#include "taskDispatcher.h"
#include "taskExecuter.h"
#include "taskConsole.h"

#if SCH_HK_ENABLED
    #include "taskHousekeeping.h"
#endif
#if SCH_COMM_ENABLE
    #include "taskCommunications.h"
#endif
#if SCH_FP_ENABLED
    #include "taskFlightPlan.h"
#endif

#ifdef FREERTOS
    void app_main();
#else
    int main(void);
#endif

#endif //SUCHAI_FLIGHT_SOFTWARE_MAIN_H
