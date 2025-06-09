class Student {
};

void calculate (long p1, long p2, double p3, double p4) {}


int main() {
  long a1 = 12345678;
  int a2 = 1;
  double a3 = 2.3455555;
  float a4 = 3.1;
  calculate(a1, a2, a3, a4); // OK
  Student s;
  // Uncomment the below statement to see the effect
  // calculate(s, 10, 5.5, 6); // Incompatible
  return 0;
}
