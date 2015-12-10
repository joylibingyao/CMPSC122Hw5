//
//  requestGenerator.cpp
//  HW5
//
//  Created by Bingyao Li on 12/9/15.
//  Copyright © 2015 CMPSC122. All rights reserved.
//
#include <iostream>
#include "requestGenerator.hpp"
#include <random>
#include <string>
#include <vector>
#include <queue>

using namespace std;


class RequestGenerator {
protected:
    queue<int> landingQueue;
    queue<int> takeoffQueue;
    vector<string> requests;
    int requestNumber=0;
    int time = 0;
    int requestTime[24];
    int p[24]={};
    
    
    int requestTimeNumber = 0;
    
    string requestType [2] ={"landing","takeoff"};
    
public:
    RequestGenerator()
    {
//generate radom exponetional request interval
        default_random_engine generator;
        exponential_distribution<double> distribution(1);
        
        
        
        for (int i=0; i<12000; ++i) {
            double number = distribution(generator);
            if (number<1.0) ++p[int(24*number)];
        }
        
        for (int i=0; i<24; ++i) {
            time+=p[i]/57;
            requestTime[i]=time;
            
        }

        
//generate all requests
        for (int j=0; j<=120; j++)
        {
            if (j==0) {
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
            
            else if (j == requestTime[requestTimeNumber]) {
                
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
        
    }

    
    vector<string> getRequests(){
        return requests;
    }
    
    void displayRequestTime(){
        cout<<"Display request time: "<<endl;
        int count = 1;
        cout<<"0"<<" ";
        while (count<24) {
            cout<<requestTime[count]<<"  ";
            
            count++;
        }
        
        cout<<endl<<endl;
    }

    
    queue<int> getLandingQueue(){
        return landingQueue;
    }
    queue<int> getTakeoffQueue(){
        return takeoffQueue;
    }
    
    int* getRequestTime(){
        return requestTime;
    }
};