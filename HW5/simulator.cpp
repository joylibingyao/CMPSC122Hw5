//
//  simulator.cpp
//  HW5
//
//  Created by Bingyao Li on 12/9/15.
//  Copyright © 2015 CMPSC122. All rights reserved.
//


#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <map>
#include <iomanip>
#include "requestGenerator.cpp"
#include <cmath>
#include "test.cpp"
#include "runway.cpp"


using namespace std;

class Simulator {
protected:
   
    RequestGenerator requestGenerator;
    queue<int> landingQueue;
    queue<int> takeoffQueue;
    vector<string> requests;
    int requestTime[24];
    
    queue<int> finalLandingQueue;
    queue<int> finalTakeoffQueue;
    

//    int time = 0;
//    int requestTime[24]={};
//    
//    int requestTimeNumber = 0;
    vector<int> prority = {};
    
    
    
    
public:
    Simulator()
    {

//
//          Test test = *new class Test();
//        landingQueue = test.getLandingQueue();
//        takeoffQueue = test.getTakeoffQueue();
        
        
        cout<<"Simulator initiated"<<endl<<endl;

        
    }
    
    void start()
    {
        
        srand(time(NULL));
        requestGenerator = *new RequestGenerator();
        landingQueue = requestGenerator.getLandingQueue();
        takeoffQueue = requestGenerator.getTakeoffQueue();
    
        requests = requestGenerator.getRequests();
        
        
        Runway runway = *new Runway(landingQueue,takeoffQueue);
        
        finalLandingQueue = runway.getLandingQueue();
        finalTakeoffQueue =runway.getTakeoffQueue();

    }
    
    void summary(){
        cout<<"SUMMARY: ----------------------------------------- "<<endl<<endl;
        
        displayLandingQueue();
        displayTakeoffQueue();
        displayRequest();
        displayRequestTime();
        cout<<"----------------------------------------------------"<<endl;
    }
    
    void displayRequestTime(){
        requestGenerator.displayRequestTime();
    }
    
    void displayRequest(){
        cout<<"Display all requests: "<<endl;
        for (int i=0; i<requests.size(); i++) {
            cout<<requests[i]<<"  ";
        }
        cout<<endl<<"Size: "<<requests.size()<<endl<<endl;
    }
    void displayLandingQueue(){
        
        int completed =landingQueue.size()-finalLandingQueue.size();
        cout<<"Original landingQueue:      "<<landingQueue.size()<<endl;
        cout<<"Final Landing Queue:        "<<finalLandingQueue.size()<<endl;
        cout<<"Completed landing request:  "<<completed<<endl;
        cout<<"Spent "<<completed*15<<" minutes in landing Queue"<<endl<<endl;
    }
    
    void displayTakeoffQueue(){
        
        int completed =takeoffQueue.size()-finalTakeoffQueue.size();
        cout<<"Original takeoffQueue:      "<<takeoffQueue.size()<<endl;
        cout<<"Final takeoff Queue:        "<<finalTakeoffQueue.size()<<endl;
        cout<<"Completed landing request:  "<<completed<<endl;
        cout<<"Spent "<<completed*15<<" minutes in landing Queue"<<endl<<endl;
    }
    
    
};