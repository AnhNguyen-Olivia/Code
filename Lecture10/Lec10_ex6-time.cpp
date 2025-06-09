#include <iostream>
#include <iomanip>


using namespace std;

const unsigned HOURMAX = 23;
const unsigned MINUTEMAX = 59;

class Time {
  unsigned hours;
  unsigned minutes;
public:
  Time(unsigned c = 0);
  Time(const Time & t);
  void setHours(unsigned h);
  void setMinutes(unsigned m);
  Time & operator ++();
  Time operator ++(int);
  Time & operator += (unsigned n);
  void display() const;
};

Time::Time(unsigned tv) {
  // 1845 to represent 18:45
  setHours(tv / 100);
  setMinutes(tv % 100);
}

Time::Time( const Time & t2) {
  minutes = t2.minutes;
  hours = t2.hours;
}

void Time::setHours(unsigned h) {
  if (h > HOURMAX) {
    cout << "ERROR: input hour is greater than HOURMAX!!\n";
    abort();
  }
  hours = h;
}

void Time::setMinutes(unsigned m) {
  if (m > MINUTEMAX) {
    cout << "ERROR: input minute is greater than MINUTEMAX!!\n";
    abort();
  }
  minutes = m;
}

// overloaded prefix ++ operator
Time & Time::operator ++() {
  if (++minutes > MINUTEMAX) {
    minutes = 0;
    hours = (hours + 1) % (HOURMAX + 1);
  }
  return *this;
}

// overloaded postfix ++ operator
Time Time::operator ++(int) {
  Time save(*this); // construct a copy
  operator ++(); // increment the time
  return save; // return the copy
}

Time & Time::operator += (unsigned n) {
  unsigned t = minutes + n;
  minutes = t % (MINUTEMAX + 1); // remaining minutes
  hours += t / (MINUTEMAX + 1); // add to hours
  hours = hours % (HOURMAX + 1); // might roll over to next day
  return *this;
}

void Time::display() const {
  cout.fill('0');
  cout << setw(2) << hours << ":" << setw(2) << minutes << endl;
}

int main() {
  Time a;
  Time b(1845);
  Time c(2359);
  (++a).display();       // 00:01
  (b++).display();       // 18:45
  (c += 15).display(); // 00:14
  (b += 20).display();  // 19:06
  Time d(1230);

for(unsigned i = 0; i < 50; i++)
  (++d).display();
}
