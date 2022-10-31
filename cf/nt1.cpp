#include <bits/stdc++.h>
using namespace std;

void primeFact(int n) { // in O(sqrt(n))
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      cout << i << " ";
      n = n / i;
    }
  }
  if (n > 1) {
    cout << n << " ";
  }
  cout << endl;
}

void printDivisor_normal(int n) { // in O(sqrt(n))
  int ct = 0;
  int sum = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cout << i << " ";
      ct++;
      sum = sum + i;
      if (n / i != i) {
        cout << n / i << " ";
        ct++;
        sum = sum + n / i;
      }
    }
  }
  cout << endl;
  cout << "count: " << ct << ", sum: " << sum << endl;
}

bool isPrime(int n) { // in O(sqrt(n))
  if (n == 1) {
    return false;
  }

  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

void sieve(int n) { // in O(nlog(log(n)))
  vector<bool> primeNos(n + 1, 1);
  primeNos[0] = primeNos[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (primeNos[i] == true) {
      for (int j = i * i; j <= n; j = j + i) {
        primeNos[j] = false;
      }
    }
  }

  for (int i = 0; i <= n; i++) {
    if (primeNos[i] == true) {
      cout << i << " ";
    }
  }
}

void sieve_fact(int n) {

  // in below 3 vectors we generally put a large value such as 10^7 to precompute lp and prime nos for large integers, it helps in queries problems
  vector<bool> primeNos(n + 1, 1);
  vector<int> hp(n + 1, 0);
  vector<int> lp(n + 1, 0);

  primeNos[0] = primeNos[1] = 0;
  for (int i = 2; i * i <= n; i++) {
    if (primeNos[i] == true) {
      lp[i] = hp[i] = i;
      for (int j = i * i; j <= n; j = j + i) {
        primeNos[j] = false;
        hp[j] = i;
        if (lp[j] == 0) {
          lp[j] = i;
        }
      }
    }
  }

// doing prime factorization by this method will only take O(logn) for one query with precomputation time of O(log(logn))
  vector<int> primefactors;
  while (n >1) { 
    int lowest_prime = lp[n];
    while (n % lowest_prime == 0) {
      n = n / lowest_prime;
      primefactors.push_back(lowest_prime);
    }
  }

  for (int var : primefactors) {
    cout << var << " ";
  }
  cout << endl;
}

//in O(logn)
void divisors_count_optm(int n) {  
  vector<int> divcount(n+1,0);
  for (int i = 2; i <= n  ; i++) {
    for (int j = i; j <= n; j+=i) {
      divcount[j]++; 
    }
  
  }
  for(int var : divcount )
  {
    cout<<var<<" ";
  }
}

int main() {
  // cout << boolalpha << isPrime(101)<<endl;
  // printDivisor_normal(36);
  // printDivisor_normal(24);
  // primeFact(36);
  // primeFact(60);
  // primeFact(24);
  // sieve(101);
  divisors_count_optm(8);
}
