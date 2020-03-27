#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<cmath>
using std::sqrt;
#include<string>
using std::to_string; using std::string;

string abIndex_friend(long ab_numerator, long ab_denominator, long f_pair){
  return to_string(ab_numerator) + "/" + to_string(ab_denominator) +
    ":" + to_string(f_pair);
}


long divisor_sum(long n)
{
    // loop only until sqrt of n 
    
    long max = sqrt(n);
	long total = 0;

	for (long i = 1; i <= max; i++)
	{
		if (n%i == 0)
		{
		    total += i;
			long result = n / i;
			
			// if result does not equal i we also add it to total
			// this captures complements and is efficient
			
			if(result != i)
			{
			    total += result;
			}
		}
	}
	return total;
}


long gcd(long a, long b)
{
    
    //use recursion and a stopping condition to pass run time test
    // Euclidean Algo
    
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd(b, (a%b));
	}
}

bool is_solitary(long num)
{
	long div_sum = divisor_sum(num);
	
	//testing using the formula from assignment sheet
	
	if (gcd(num, div_sum) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}

}

string friendly_check(long input, long limit)

{
    
    // establish ration for input
	long div_sum = divisor_sum(input);
	long gcd_num = gcd(div_sum, input);

	long numer = div_sum / gcd_num;
	long denom = input / gcd_num;

	for (long iter = 2; iter <= limit; ++iter)
	{
	    //make sure loop doesn't stop at input value
		if (iter != input)
		{
		    
		    //establish ratio for iterator
			long div_sum_2 = divisor_sum(iter);
			long gcd_num_2 = gcd(div_sum_2, iter);

			long numer_2 = div_sum_2 / gcd_num_2;
			long denom_2 = iter / gcd_num_2;

            //check equivalence 
			if (numer_2 == numer and denom_2 == denom)
			{
				return abIndex_friend(numer, denom, iter);
			}
		}
	}
	
	return abIndex_friend(numer, denom, -1);
}


int main (){
  cout << boolalpha;   // print true or false for bools
  int test;
  cin >> test;
  switch (test) {
  case 1 : {   // divisor sum test
    long input;
    cin >> input;
    cout << divisor_sum(input) << endl;
    break;
  } // of case 1

  case 2:{    // gcd test
    long first, second;
    cin >> first >> second;
    cout << gcd(first, second) << endl;
    break;
  } // of case 2

  case 3: {    // is_solitary test
    long input;
    cin >> input;
    cout << is_solitary(input) << endl;
    break;
  } // of case 3

  case 4: {
    // friend check. Make sure the return value is the
    // result of calling abIndex_friend, a string!
    long input, limit;
    cin >> input >> limit;
    cout << friendly_check(input, limit) << endl;
    break;
  } // of case 4
    
  } // of switch
} // of main
