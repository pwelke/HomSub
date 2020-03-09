#include <iostream>
#include "experiments/test_runner.h"
#include "experiments/test_factory.h"
#include "experiments/test.h"
#include <chrono>


void TestRunner::Run() {
    srand(settings_.GetRandomSeed());
    if(settings_.ShouldRunSingleTest()) {
        RunTest(settings_.GetSingleTest());
    }
    
    if(settings_.ShouldRunTestMask()) {
        RunTestFromMask(settings_.GetTestMask());
    }
}

void TestRunner::RunTestFromMask(int mask)
{
    for(int i = 0; i < 32; i++) {
        if((1 << i) & mask) {
            RunTest(i);
        }
    }
}

void TestRunner::RunTest(Test test)
{
    std::cout << test.GetName() << ":\t";
    
    float prTestRuntime = (float) settings_.GetPrTestRuntime();
    float elapsedTime = 0;
    float latestRuntime = 0;
    int i = 1;
    
    //Run test several times until met timelimit
    while(elapsedTime < prTestRuntime) {
        auto start = std::chrono::high_resolution_clock::now();
        test.Run(i);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        float seconds = (float)duration.count() / (float)1000000;
        
        elapsedTime += seconds;
        latestRuntime = seconds;
        i++;
    }
    
    float timeResult = test.isIncremental() ? latestRuntime : elapsedTime / (float) i;
    
    std::cout << i << ", " << timeResult << "s" << std::endl;
}

void TestRunner::RunTest(int testNum)
{
    std::unique_ptr<Test> t = TestFactory::GetTest(testNum);
    if(t) {
        RunTest(*t);
    }
}

void TestRunner::PrintHelp()
{
    std::cout << "Give the program a sequence of parameters in order to adjust execution. Supported parameters are described here:\n" << std::endl;
    std::cout << "-help     | Get this help screen" << std::endl;
    std::cout << "-list     | List all tests" << std::endl;
    std::cout << "-test t   | Run a specific test" << std::endl;
    std::cout << "-mask m   | Run several tests masked by given signed integer (-1 runs all)" << std::endl;
    std::cout << "-tws  t   | Specify which TreeWidthSolve should be used from: tamaki" << std::endl;
    std::cout << "-run  h g | Count occurences of pattern h in host g" << std::endl;
    
    std::cout << std::endl;
}

void TestRunner::PrintTests()
{
    std::cout << "Tests:" << std::endl;
    for(int i = 0; i < TestFactory::TestCount(); i++) {
        std::shared_ptr<Test> t = TestFactory::GetTest(i);
        std::cout << i << ": " << t->GetName() << ", " << t->GetDescription() << std::endl;
    }
}