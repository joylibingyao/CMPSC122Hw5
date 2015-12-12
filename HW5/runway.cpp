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
    bool avaliable = true;
    
public:
    Runway(queue<int> newlandingQueue,queue<int> newtakeoffQueue)
    {
        landingQueue= newlandingQueue;
        takeoffQueue = newtakeoffQueue;
        
    }
    

    bool isAvalible(int i){
        if (i%15 == 0) {
//            cout<<"true"<<endl;
            return true;
        }
        else{
            return false;
        }

    }
    
    queue<int> getLandingQueue(){
//        cout<<landingQueue.size()<<"-----------------size";
        return landingQueue;
    }
    queue<int> getTakeoffQueue(){
        return takeoffQueue;
    }
    
    
};
