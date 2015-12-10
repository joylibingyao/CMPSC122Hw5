//
//  simulator.cpp
//  HW5
//
//  Created by Bingyao Li on 12/9/15.
//  Copyright © 2015 CMPSC122. All rights reserved.
//

#include "simulator.hpp"
#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <map>
#include <iomanip>

using namespace std;

class Simulator {
protected:
   
    
    queue<int> landingQueue;
    queue<int> takeoffQueue;
    vector<string> requests;
    int requestNumber=0;
    int time = 0;
    int requestTime[24]={};
    
    int requestTimeNumber = 0;
    
    string requestType [2] ={"landing","takeoff"};
    
    
    
public:
    Simulator()
    {
//        srand(time(NULL)); /* initialize random seed: */ 
//        ranInterval = rand() % 25;//make request size random between 0 and 120
        cout<<"Simulator initiated"<<endl;
    }
    
    void start()
    {
        
        
        default_random_engine generator;
        exponential_distribution<double> distribution(1);
        
        int p[24]={};
        
        for (int i=0; i<12000; ++i) {
            double number = distribution(generator);
            if (number<1.0) ++p[int(24*number)];
        }
        
//        requestTime[0]=0;
        for (int i=0; i<24; ++i) {
//            cout<<p[i]/57<<endl;
             time+=p[i]/57;
            requestTime[i]=time;
//            cout<<requestTime[i]<<endl;
            
        }
        
        
//        cout<<sum<<endl;
        
        
        for (int j=0; j<=120; j++)
        {
            
            
            if (j== 0||j == requestTime[requestTimeNumber]) {
//                cout<<j<<endl;
                cout<<"request "<<requestTime[requestTimeNumber]<<endl;
                requestTimeNumber++;
                int ran;
                ran = rand()%2;// generate number between 0 and 1
                if (ran == 0) {
                    requests.push_back(requestType[ran]);// lading request
                    landingQueue.push(j);
                }
                else if(ran == 1){
                    requests.push_back(requestType[ran]);//takeoff request
                    takeoffQueue.push(j);
                }
            }
        }
        
        
        for (int n = 0; n<2; n++)
        {// two lanes
            for (int i=1; i<=120; i++)
            {
                if ((i==1||i%15 == 0) && requestNumber<= requests.size())//complet request every 15 min
                {
                    
                    if (requests[requestNumber] == "landing" && !landingQueue.empty()) {
                        landingQueue.pop();
                        requestNumber++;
                    }
                    else if(requests[requestNumber] == "takeoff" && !takeoffQueue.empty()){
                        takeoffQueue.pop();
                        requestNumber++;
                    }
                    
                }
            }
        }
        
        
        



        
        
    }
    
    
    
    void displayRequest(){
        for (int i=0; i<requests.size(); i++) {
            cout<<requests[i]<<endl;
        }
        cout<<"Size: "<<requests.size()<<endl;
    }
    void displayLandingQueue(){
//        for(auto it = landingQueue.front(); it!=landingQueue.back();++it)
//            std::cout << it << "\n";
        cout<<"Landing Queue: "<<landingQueue.size()<<endl;
    }
    void displayTakeoffQueue(){
//        for(auto it = takeoffQueue.front(); it!=takeoffQueue.back();++it)
//            std::cout << it << "\n";
        cout<<"takeoff Queue: "<<takeoffQueue.size()<<endl;
    }
    
};