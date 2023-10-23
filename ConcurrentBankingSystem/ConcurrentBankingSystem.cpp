#include <iostream>
#include <thread>
#include "Banque.h"
#include "Journal.h"
#include "ConcurrentAccess.h"


int main()
{
    Journal myJournal;
    Banque myBanque(myJournal);

    myBanque.AddAccount(1, 1000);

     std::shared_ptr<Compte> account1 = myBanque.FindAccount(1);
    if (!account1) {
        std::cerr << "Account not found!" << std::endl;
        return 1;
    }

    ConcurrentAccess concurrentAccess(*account1);
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(std::thread(concurrentAccess));
    }

    for (std::thread& th : threads) {
        th.join();
    }

    myJournal.ShowLog();
    std::cout << std::endl << "Final balance: " << account1->GetBalance() << std::endl;

    return 0;
}
