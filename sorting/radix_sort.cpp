//radix sort in c++ ?
// what a mess...
c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;


// determine index for c
const int iC = k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0;
// post-increment c (as it is it could become a pre-increment as well)
c[iC]++;


// determine index for c
const int iC
  // check whether k is (not) exceeding the size of a
  = k < a[j].size()
  // then 
  ? (int)(unsigned char)a[j][k] + 1
  // else
  : 0;


b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];


const int iC = k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0;
const int iB = c[iC - 1]; // What?
b[iB] = a[r];


c = new int[257];


#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/* helper to find max. length in data strings
 */
size_t maxLength(const std::vector<std::string> &data)
{
  size_t lenMax = 0;
  for (const std::string &value : data) {
    if (lenMax < value.size()) lenMax = value.size();
  }
  return lenMax;
}

/* a naive implementation of radix sort
 * like described in https://en.wikipedia.org/wiki/Radix_sort
 */
void radixSort(std::vector<std::string> &data)
{
  /* A char has 8 bits - which encode (unsigned) the numbers of [0, 255].
   * Hence, 256 buckets are used for sorting.
   */
  std::vector<std::string> buckets[256];
  // determine max. length of input data:
  const size_t len = maxLength(data);
  /* iterate over data for according to max. length
   */
  for (size_t i = len; i--;) { // i-- -> check for 0 and post-decrement
    // sort data into buckets according to the current "digit":
    for (std::string &value : data) {
      /* digits after end of string are considered as '\0'
       * because 0 is the usual end-marker of C strings
       * and the least possible value of an unsigned char.
       * This shall ensure that an string goes before a longer
       * string with same prefix.
       */
      const unsigned char digit = i < value.size() ? value[i] : '\0';
      // move current string into the corresponding bucket
      buckets[digit].push_back(std::move(value));
    }
    // store buckets back into data (preserving current order)
    data.clear();
    for (std::vector<std::string> &bucket : buckets) {
      // append bucket to the data
      data.insert(data.end(),
        std::make_move_iterator(bucket.begin()),
        std::make_move_iterator(bucket.end()));
      bucket.clear();
    }
  }
}

/* counting sort as helper for the not so naive radix sort
 */
void countSort(std::vector<std::string> &data, size_t i)
{
  /* There are 256 possible values for an unsigned char
   * (which may have a value in [0, 255]).
   */
  size_t counts[256] = { 0 }; // initialize all counters with 0.
  // count how often a certain charater appears at the place i
  for (const std::string &value : data) {
    /* digits after end of string are considered as '\0'
     * because 0 is the usual end-marker of C strings
     * and the least possible value of an unsigned char.
     * This shall ensure that an string goes before a longer
     * string with same prefix.
     */
    const unsigned char digit = i < value.size() ? value[i] : '\0';
    // count the resp. bucket counter
    ++counts[digit];
  }
  // turn counts of digits into offsets in data
  size_t total = 0;
  for (size_t &count : counts) {
#if 0 // could be compact (and, maybe, confusing):
    total = count += total; // as C++ assignment is right-associative
#else // but is the same as:
    count += total; // add previous total sum to count
    total = count; // remember new total
#endif // 0
  }
  // an auxiliary buffer to sort the input data into.
  std::vector<std::string> buffer(data.size());
  /* Move input into aux. buffer
   * while using the bucket offsets (the former counts)
   * for addressing of new positions.
   * This is done backwards intentionally as the offsets
   * are decremented from end to begin of partitions.
   */
  for (size_t j = data.size(); j--;) { // j-- -> check for 0 and post-decrement
    std::string &value = data[j];
    // see comment for digit above...
    const unsigned char digit = i < value.size() ? value[i] : '\0';
    /* decrement offset and use as index
     * Arrays (and vectors) in C++ are 0-based.
     * Hence, this is adjusted respectively (compared to the source of algorithm).
     */
    const size_t k = --counts[digit];
    // move input element into auxiliary buffer at the determined offset
    buffer[k] = std::move(value);
  }
  /* That's it.
   * Move aux. buffer back into data.
   */
  data = std::move(buffer);
}

/* radix sort using count sort internally
 */
void radixCountSort(std::vector<std::string> &data)
{
  // determine max. length of input data:
  const size_t len = maxLength(data);
  /* iterate over data according to max. length
   */
  for (size_t i = len; i--;) { // i-- -> check for 0 and post-decrement
    countSort(data, i);
  }
}

/* output of vector with strings
 */
std::ostream& operator<<(std::ostream &out, const std::vector<std::string> &data)
{
  const char *sep = " ";
  for (const std::string &value : data) {
    out << sep << '"' << value << '"';
    sep = ", ";
  }
  return out;
}

/* do a test for certain data
 */
void test(const std::vector<std::string> &data)
{
  std::cout << "Data: {" << data << " }\n";
  std::vector<std::string> data1 = data;
  radixSort(data1);
  std::cout << "Radix Sorted:       {" << data1 << " }\n";
  std::vector<std::string> data2 = data;
  radixCountSort(data2);
  std::cout << "Radix Count Sorted: {" << data2 << " }\n";
}

/* helper to turn a text into a vector of strings
 * (by separating at white spaces)
 */
std::vector<std::string> tokenize(const char *text)
{
  std::istringstream in(text);
  std::vector<std::string> tokens;
  for (std::string token; in >> token;) tokens.push_back(token);
  return tokens;
}

/* main program
 */
int main()
{
  // do some tests:
  test({ "Hi", "He", "Hello", "World", "Wide", "Web" });
  test({ });
  test(
    tokenize(
      "Radix sort dates back as far as 1887 to the work of Herman Hollerith on tabulating machines.\n"
      "Radix sorting algorithms came into common use as a way to sort punched cards as early as 1923.\n"
      "The first memory-efficient computer algorithm was developed in 1954 at MIT by Harold H. Seward.\n"
      "Computerized radix sorts had previously been dismissed as impractical "
      "because of the perceived need for variable allocation of buckets of unknown size.\n"
      "Seward's innovation was to use a linear scan to determine the required bucket sizes and offsets beforehand, "
      "allowing for a single static allocation of auxiliary memory.\n"
      "The linear scan is closely related to Seward's other algorithm - counting sort."));
}


