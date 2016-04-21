#Zadania
##Zad 1
Napisz program, który zamieni liczbę z przedziału od zera do miliona na polski liczebnik. Na przykład dla `123 456` będzie to *sto dwadzieścia trzy tysiące czterysta pięćdziesiąt sześć*.

##Zad 2
Wiemy, że dla każdej liczby naturalnej `n` możemy znaleźć taką liczbę `k`, gdzie iloczyn `n * k` w zapisie dziesiętnym składa się wyłącznie z zer i jedynek. Napisz program, który dla zadanej liczby `n` znajdzie `k` spełniające ten warunek.

#Zadanie końcowe
Połącz oba programy tak, aby jako argument wiersza poleceń przekazywać do niego `n`, a podsumowanie poszukiwań `k` oraz wynik iloczynu wyświetlić użytkownikowi w postaci polskich liczebników.

#Algorytm szukający k
założenia: n - liczba naturalna; k - liczba naturalna; dla n = 0 k wynosi 0; dla n > 0 k powinno być większe od 0; n*k < 1000000;
algorytm zwiększa k przy każdej iteracji sprawdzajac czy wynik składa się z samych zer i jedynek, jeżeli n * k >999999 zwracane jest zero