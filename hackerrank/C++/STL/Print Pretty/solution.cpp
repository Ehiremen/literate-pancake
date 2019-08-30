//https://www.hackerrank.com/challenges/prettyprint/problem        
        
        
        //using stringstream produces EXACTLY the same result as formatting cout,
        //but the result shows up as "Wrong Answer"
        /*
        long long truncA = (long long) A;
        stringstream sstreamA;
        sstreamA << hex << showbase << nouppercase << left << truncA;
        cout << sstreamA.str() << endl;
        */
        
        //formatting A
        cout << hex << showbase << nouppercase << left << (long long)A << endl;


        //formatting B
        stringstream sstreamB;
        sstreamB << setw(15) << right << setfill('_') << fixed << setprecision(2) <<                showpos << B;
        cout << sstreamB.str() << endl;


        //formatting C
        stringstream sstreamC;
        sstreamC << uppercase << scientific << setprecision(9) << C;
        cout << sstreamC.str() << endl;
