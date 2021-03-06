#include "include/defs/defs.h"
#include "include/board/board.h"
#include "include/robotController/controllerMessor2.h"
#include "include/robotModel/robotMessor2.h"
#include "include/board/boardDynamixel.h"
#include "3rdParty/dynamixel/dynamixel.h"
#include "3rdParty/dynamixel/dxl_hal.h"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace controller;


int main( int argc, const char** argv )
{

    try {
        vector <float_type> motorSpeed;
        for(int i = 0; i < 18; i++ ){
        motorSpeed.push_back(10);
        }
        Board* board = createBoardDynamixel();

        std::vector<float_type> position1;
        position1.push_back((0*M_PI)/180);
        position1.push_back((24*M_PI)/180);
        position1.push_back((114*M_PI)/180);

        board->setSpeed(motorSpeed);

        for(int i=0; i<6; i++)
        {
            board->setPosition(i, position1);
        }

        RobotController* controller = createControllerMessor2("controllerMessor2.xml");

        float_type speedo = ((ControllerMessor2*)controller)->speedPajak();

        char start;

        Mat34 initialFront(Mat34::Identity());
        Mat34 initial0(Mat34::Identity());
        Mat34 initialMid(Mat34::Identity());
        Mat34 initialBack(Mat34::Identity());

        Mat34 legBackFront(Mat34::Identity());
        Mat34 legBackMid(Mat34::Identity());
        Mat34 legBackBack(Mat34::Identity());

        Mat34 legUpFront(Mat34::Identity());
        Mat34 legUpMid(Mat34::Identity());
        Mat34 legUpBack(Mat34::Identity());

        Mat34 legUpRFront(Mat34::Identity());
        Mat34 legUpRMid(Mat34::Identity());
        Mat34 legUpRBack(Mat34::Identity());

        vector<Mat34> trajBackFront;
        vector<Mat34> trajUpFront;
        vector<Mat34> trajUpRFront;

        vector<Mat34> trajBackMid;
        vector<Mat34> trajUpMid;
        vector<Mat34> trajUpRMid;

        vector<Mat34> trajBackBack;
        vector<Mat34> trajUpBack;
        vector<Mat34> trajUpRBack;

        vector<Mat34> trajInitialF;
        vector<Mat34> trajInitialM;
        vector<Mat34> trajInitialB;
        vector<Mat34> trajInitial0;

        std::vector<std::vector<Mat34>> executeLegsMovementBack;
        std::vector<std::vector<Mat34>> executeLegsMovementInitial;


        initialFront(1,3)=-0.12;
        legBackFront(1,3)=-0.04;
        legUpFront(0,3) = -0.05;
        legUpFront(1,3) = -0.12;
        legUpFront(2,3) = -0.1;


        trajBackFront.push_back(legBackFront);
        trajUpFront.push_back(legUpFront);
        trajUpFront.push_back(initialFront);

        initialMid(1,3)=-0.04;
        legBackMid(1,3)=0.04;
        legUpMid(0,3) = -0.05;
        legUpMid(1,3) = 0.00;
        legUpMid(2,3) = -0.1;

        trajBackMid.push_back(legBackMid);
        trajUpMid.push_back(legUpMid);
        trajUpMid.push_back(initialMid);

        initialBack(1,3)=0.04;
        legBackBack(1,3)=0.12;
        legUpBack(0,3) = -0.05;
        legUpBack(1,3) = 0.08;
        legUpBack(2,3) = -0.1;

        trajBackBack.push_back(legBackBack);
        trajUpBack.push_back(legUpBack);
        trajUpBack.push_back(initialBack);

        legUpRFront(0,3) = 0.05;
        legUpRFront(1,3) = -0.08;
        legUpRFront(2,3) = -0.1;

        legUpRBack(0,3) = 0.05;
        legUpRBack(1,3) = 0.04;
        legUpRBack(2,3) = -0.1;

        legUpRMid(0,3) = 0.05;
        legUpRMid(1,3) = 0.00;
        legUpRMid(2,3) = -0.1;

        trajUpRFront.push_back(legUpRFront);
        trajUpRFront.push_back(initialFront);

        trajUpRMid.push_back(legUpRMid);
        trajUpRMid.push_back(initialMid);

        trajUpRBack.push_back(legUpRBack);
        trajUpRBack.push_back(initialBack);

        executeLegsMovementBack.push_back(trajUpFront);
        executeLegsMovementBack.push_back(trajBackBack);
        executeLegsMovementBack.push_back(trajBackMid);
        executeLegsMovementBack.push_back(trajBackMid);
        executeLegsMovementBack.push_back(trajBackBack);
        executeLegsMovementBack.push_back(trajBackFront);

        usleep(1000000);

        ///////RUCH PIĘCIOPODPOROWY/////////

        std::vector<unsigned char> legNos024135;

        legNos024135.push_back(0);
        legNos024135.push_back(2);
        legNos024135.push_back(4);
        legNos024135.push_back(1);
        legNos024135.push_back(3);
        legNos024135.push_back(5);

        trajInitialF.push_back(initialFront);
        trajInitialM.push_back(initialMid);
        trajInitialB.push_back(initialBack);
        executeLegsMovementInitial.push_back(trajInitialF);
        executeLegsMovementInitial.push_back(trajInitialB);
        executeLegsMovementInitial.push_back(trajInitialM);
        executeLegsMovementInitial.push_back(trajInitialM);
        executeLegsMovementInitial.push_back(trajInitialB);
        executeLegsMovementInitial.push_back(trajInitialF);

        controller->moveLegs(legNos024135, executeLegsMovementInitial, speedo, 0, 0);

        cin >> start;



        while(true)
        {
            controller->moveLegs(legNos024135, executeLegsMovementBack, speedo, 1, 0);

            controller->moveLeg(5, trajUpRFront, speedo, 1, 0);
            controller->moveLeg(1, trajUpMid, speedo, 1, 0);
            controller->moveLeg(4, trajUpRMid, speedo, 1, 0);
            controller->moveLeg(2, trajUpBack, speedo, 1, 0);
            controller->moveLeg(3, trajUpRBack, speedo, 1, 0);

        }

        if (((ControllerMessor2*)controller)->useVisualizer()){
            ((ControllerMessor2*)controller)->finishVisualizer();
        }
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }


    return 0;
}
