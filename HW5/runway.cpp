//
//  runway.cpp
//  HW5
//
//  Created by Bingyao Li on 12/10/15.
//  Copyright © 2015 CMPSC122. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <queue>


using namespace std;

class Runway {
protected:
    queue<int> landingQueue;
    queue<int> takeoffQueue;
    
public:
    Runway(queue<int> newlandingQueue,queue<int> newtakeoffQueue)
    {
        landingQueue= newlandingQueue;
        takeoffQueue = newtakeoffQueue;
        
        for (int n = 0; n<2; n++) {
            for (int i=1; i<=120; i++)
            {
                
                if (i==1||i%15 == 0) //complet request every 15 min
                {
                    if (abs(landingQueue.front()-i)<15 && !landingQueue.empty()) {//make landing request priority
                        landingQueue.pop();
                    }
                    else if (landingQueue.front()<takeoffQueue.front() && !landingQueue.empty()) {//complete request that is sent earlier
                        landingQueue.pop();
                    }
                    else if (landingQueue.front()>takeoffQueue.front() && !takeoffQueue.empty()){
                        takeoffQueue.pop();
                    }
                    
                    
                }
            }
        }
    }
    
    
    queue<int> getLandingQueue(){
        return landingQueue;
    }
    queue<int> getTakeoffQueue(){
        return takeoffQueue;
    }
    
    
};
