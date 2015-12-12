//
//  main.cpp
//  HW5
//
//  Created by Bingyao Li on 12/9/15.
//  Copyright © 2015 CMPSC122. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
#include "simulator.cpp"

using namespace std;


int main(int argc, const char * argv[]) {
    
    Simulator simulator = *new Simulator();
    
    simulator.start();
    simulator.summary();
    simulator.aveTimeLanding();
    simulator.aveTimeTakeoff();

    return 0;
}
