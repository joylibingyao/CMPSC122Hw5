//
//  test.cpp
//  HW5
//
//  Created by Bingyao Li on 12/9/15.
//  Copyright © 2015 CMPSC122. All rights reserved.
//

#include <random>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Test {
    queue<int> landingQueue;
    queue<int> takeoffQueue;
    
public:
    Test(){
        landingQueue.push(0);
        landingQueue.push(16);
        landingQueue.push(20);
        landingQueue.push(119);
        
        takeoffQueue.push(10);
         takeoffQueue.push(13);
         takeoffQueue.push(14);
         takeoffQueue.push(17);
         takeoffQueue.push(30);
        
    }
    
    queue<int> getLandingQueue(){
        return landingQueue;
    }
    queue<int> getTakeoffQueue(){
        return takeoffQueue;
    }
    
};