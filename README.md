Vlad Andra, 321CC

*** TEMA 2: Planificator de thread-uri ***

Timp de implementare: 3-4 ore

1. Introducere
    Aceasta tema mi s-a parut mult mai interesanta decat prima, fiind mult mai clar ceea ce ai de facut.
    M-am focusat pe a intelege conceptele de baza (thread, semafor, scheduler, fork) si din pacate
    nu m-am incadrat in timp pentru a implementa in tema mea starile thread-urilor si semafoarele.
    Urma sa initializez cate un semafor pentru fiecare thread cu sem_init si sa tin cont de
    thread-ul care e running, implementand astfel o rutina, sa actualizez/blochez thread-ul
    cu sem_wait si sa iau in considerare cat din timpul de executie al thread-ului
    se consuma in so_exec. Trebuie tinut cont si de eliberarea semaforului cand e cazul.
    De asemenea, urma sa implementez coada cu prioritati ca o structura
    separata, insa am ales sa o las reprezentata ca un vector momentan. 

2. Implementare
    Initial, am implementat structurile pentru thread si planificator. Variabila globala "ok" 
    verifica daca planificatorul a fost initializat sau nu. In so_init am verificat sa se
    respecte conditiile din cerinta si daca planificatorul nostru a fost deja initializat. 
    Dupa initializarea structurii de scheduler am realizat so_end, unde m-am asigurat ca eliberez 
    memoria alocata anterior. So_wait si so_exec verifica de asemenea conditiile de baza, 
    fara a avea implementarea semaforului pentru thread-uri. In so_fork am initializat
    thread-ul respectiv, caruia i-am dat start si join cu ajutorul functiilor din biblioteca
    pthread.h. Apelarea functiei pthread_create a necesitat implementarea rutinei
    start_thread, unde rulam handler-ul thread-ului respectiv, care primeste ca 
    argument prioritatra acestuia. Nu am mai implementat partea in care asteptam ca
    thread-ul sa fie planificat si schimbam statusul thread-ului pentru iesire.
    





