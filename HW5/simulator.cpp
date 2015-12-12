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
    
//    vector<int> landingComplete = {};
//    vector<int> takeoffComplete = {};
    
    vector<string> requests;
    int requestTime[24];
    vector<int> landingComplete = {};
    vector<int> takeoffComplete = {};
//    int takeoffComplete[120]={};
    
    queue<int> finalLandingQueue;
    queue<int> finalTakeoffQueue;
    


    vector<int> prority = {};
    int landingCompleteNum=0;
    int takeoffCompleteNum=0;
   
    
public:
    Simulator()
    
    {
        
        srand(time(NULL));
        requestGenerator = *new RequestGenerator();
        finalLandingQueue=requestGenerator.getLandingQueue();
        landingQueue = requestGenerator.getLandingQueue();
        
        finalTakeoffQueue= requestGenerator.getTakeoffQueue();
        
        takeoffQueue = requestGenerator.getTakeoffQueue();

        
        requests = requestGenerator.getRequests();
        
    
        
        cout<<"Simulator initiated"<<endl<<endl;

        
    }
    
    void start()
    {
        
        
        Runway runway1 = *new Runway(landingQueue,takeoffQueue);
        Runway runway2 = *new Runway(landingQueue,takeoffQueue);
        
       
        for (int i = 1; i<121; i++) {//time run 120 minutes

            for (int n = 0; n<2; n++) {//check twice since two runways can run at the same time
                if (runway1.isAvalible(i)==true || runway2.isAvalible(i)==true) {// complete reqest when avaliable

                    if (i-finalLandingQueue.front()<15 && i-finalLandingQueue.front()>0&& !finalLandingQueue.empty()) {//make landing request priority
                        
//                        cout<<i<<" landed "<<finalLandingQueue.front()<<" here "<<endl;
                        landingComplete.push_back(i);
                        landingCompleteNum++;
                        finalLandingQueue.pop();
                    }
                    else if (finalLandingQueue.front()<takeoffQueue.front() && i-finalLandingQueue.front()>0 && !finalLandingQueue.empty()) {//complete request that is sent earlier
                        finalLandingQueue.pop();
//                        cout<<i<<" landed "<<finalLandingQueue.front()<<" there "<<endl;
//                        cout<<"landed "<<i;
                        landingComplete.push_back(i);
                        landingCompleteNum++;
                    }
                    else if (finalLandingQueue.front()>finalTakeoffQueue.front()&& i-finalTakeoffQueue.front()>0 && !finalTakeoffQueue.empty()){
                        finalTakeoffQueue.pop();
                        takeoffComplete.push_back(i);
                        takeoffCompleteNum++;
                    }
                }
            }
            
        }
        
        


    }
    
    double aveTimeLanding(){
        int sum = 0;
        queue<int> temp = landingQueue;
//        cout<<temp.front()<<"front         ";
//        cout<<landingComplete[0];
//        cout<<landingQueue.front();
        for (int i = 0; i<landingQueue.size(); i++) {
            if (i<=landingComplete.size()-1) {
                
//                cout<<landingComplete[i]<<"complete  ";
//                cout<<temp.front()<<endl;
//                cout<<finalLandingQueue.size();
                sum += landingComplete[i]-temp.front();
                
                temp.pop();
            }else{
                sum += 120-temp.front();
                temp.pop();
            }
        }
        
//        cout<<sum;
        return sum/landingQueue.size();
        
    }
    
    double aveTimeTakeoff(){
        int sum = 0;
        queue<int> temp = takeoffQueue;
        //        cout<<temp.front()<<"front         ";
        //        cout<<landingComplete[0];
        //        cout<<landingQueue.front();
        for (int i = 0; i<takeoffQueue.size(); i++) {
            if (i<=takeoffComplete.size()-1) {
                
                //                cout<<landingComplete[i]<<"complete  ";
                //                cout<<temp.front()<<endl;
                //                cout<<finalLandingQueue.size();
                sum += takeoffComplete[i]-temp.front();
                
                temp.pop();
            }else{
                sum += 120-temp.front();
                temp.pop();
            }
        }
        
        return sum/takeoffQueue.size();
        
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
        cout<<"Spent "<< aveTimeLanding() <<" minutes in landing Queue"<<endl<<endl;
    }
    
    void displayTakeoffQueue(){
        
        int completed =takeoffQueue.size()-finalTakeoffQueue.size();
        cout<<"Original takeoffQueue:      "<<takeoffQueue.size()<<endl;
        cout<<"Final takeoff Queue:        "<<finalTakeoffQueue.size()<<endl;
        cout<<"Completed takeoff request:  "<<completed<<endl;
        cout<<"Spent "<<aveTimeTakeoff()<<" minutes in landing Queue"<<endl<<endl;
    }
    
    
};