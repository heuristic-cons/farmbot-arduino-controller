
/*
 * F14Handler.cpp
 *
 *  Created on: 2014/07/21
 *      Author: MattLech
 */

#include "F14Handler.h"


static F14Handler* instance;

F14Handler * F14Handler::getInstance() {
        if (!instance) {
                instance = new F14Handler();
        };
        return instance;
}
;

F14Handler::F14Handler() {
}

int F14Handler::execute(Command* command) {

	int ret = 0;

        if (LOGGING) {
                Serial.print("R99 CALIBRATE X\n");
        }

        ret = StepperControl::getInstance()->calibrateAxis(0);

	if (ret == 0) {
		StepperControl::getInstance()->moveAbsoluteConstant(0,0,0, 0,0,0, true, false, false);
	}

        if (LOGGING) {
                CurrentState::getInstance()->print();
        }

        return 0;
}


