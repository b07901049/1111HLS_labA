#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_d_o_0 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_0.dat"
#define AUTOTB_TVOUT_d_o_0 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_0.dat"
#define AUTOTB_TVIN_d_o_1 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_1.dat"
#define AUTOTB_TVOUT_d_o_1 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_1.dat"
#define AUTOTB_TVIN_d_o_2 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_2.dat"
#define AUTOTB_TVOUT_d_o_2 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_2.dat"
#define AUTOTB_TVIN_d_o_3 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_3.dat"
#define AUTOTB_TVOUT_d_o_3 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_3.dat"
#define AUTOTB_TVIN_d_o_4 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_4.dat"
#define AUTOTB_TVOUT_d_o_4 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_4.dat"
#define AUTOTB_TVIN_d_o_5 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_5.dat"
#define AUTOTB_TVOUT_d_o_5 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_5.dat"
#define AUTOTB_TVIN_d_o_6 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_6.dat"
#define AUTOTB_TVOUT_d_o_6 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_6.dat"
#define AUTOTB_TVIN_d_o_7 "../tv/cdatafile/c.axi_interfaces.autotvin_d_o_7.dat"
#define AUTOTB_TVOUT_d_o_7 "../tv/cdatafile/c.axi_interfaces.autotvout_d_o_7.dat"
#define AUTOTB_TVIN_d_i_0 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_0.dat"
#define AUTOTB_TVOUT_d_i_0 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_0.dat"
#define AUTOTB_TVIN_d_i_1 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_1.dat"
#define AUTOTB_TVOUT_d_i_1 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_1.dat"
#define AUTOTB_TVIN_d_i_2 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_2.dat"
#define AUTOTB_TVOUT_d_i_2 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_2.dat"
#define AUTOTB_TVIN_d_i_3 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_3.dat"
#define AUTOTB_TVOUT_d_i_3 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_3.dat"
#define AUTOTB_TVIN_d_i_4 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_4.dat"
#define AUTOTB_TVOUT_d_i_4 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_4.dat"
#define AUTOTB_TVIN_d_i_5 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_5.dat"
#define AUTOTB_TVOUT_d_i_5 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_5.dat"
#define AUTOTB_TVIN_d_i_6 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_6.dat"
#define AUTOTB_TVOUT_d_i_6 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_6.dat"
#define AUTOTB_TVIN_d_i_7 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_7.dat"
#define AUTOTB_TVOUT_d_i_7 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_7.dat"
#define AUTOTB_TVIN_d_i_8 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_8.dat"
#define AUTOTB_TVOUT_d_i_8 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_8.dat"
#define AUTOTB_TVIN_d_i_9 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_9.dat"
#define AUTOTB_TVOUT_d_i_9 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_9.dat"
#define AUTOTB_TVIN_d_i_10 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_10.dat"
#define AUTOTB_TVOUT_d_i_10 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_10.dat"
#define AUTOTB_TVIN_d_i_11 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_11.dat"
#define AUTOTB_TVOUT_d_i_11 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_11.dat"
#define AUTOTB_TVIN_d_i_12 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_12.dat"
#define AUTOTB_TVOUT_d_i_12 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_12.dat"
#define AUTOTB_TVIN_d_i_13 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_13.dat"
#define AUTOTB_TVOUT_d_i_13 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_13.dat"
#define AUTOTB_TVIN_d_i_14 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_14.dat"
#define AUTOTB_TVOUT_d_i_14 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_14.dat"
#define AUTOTB_TVIN_d_i_15 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_15.dat"
#define AUTOTB_TVOUT_d_i_15 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_15.dat"
#define AUTOTB_TVIN_d_i_16 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_16.dat"
#define AUTOTB_TVOUT_d_i_16 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_16.dat"
#define AUTOTB_TVIN_d_i_17 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_17.dat"
#define AUTOTB_TVOUT_d_i_17 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_17.dat"
#define AUTOTB_TVIN_d_i_18 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_18.dat"
#define AUTOTB_TVOUT_d_i_18 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_18.dat"
#define AUTOTB_TVIN_d_i_19 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_19.dat"
#define AUTOTB_TVOUT_d_i_19 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_19.dat"
#define AUTOTB_TVIN_d_i_20 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_20.dat"
#define AUTOTB_TVOUT_d_i_20 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_20.dat"
#define AUTOTB_TVIN_d_i_21 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_21.dat"
#define AUTOTB_TVOUT_d_i_21 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_21.dat"
#define AUTOTB_TVIN_d_i_22 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_22.dat"
#define AUTOTB_TVOUT_d_i_22 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_22.dat"
#define AUTOTB_TVIN_d_i_23 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_23.dat"
#define AUTOTB_TVOUT_d_i_23 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_23.dat"
#define AUTOTB_TVIN_d_i_24 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_24.dat"
#define AUTOTB_TVOUT_d_i_24 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_24.dat"
#define AUTOTB_TVIN_d_i_25 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_25.dat"
#define AUTOTB_TVOUT_d_i_25 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_25.dat"
#define AUTOTB_TVIN_d_i_26 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_26.dat"
#define AUTOTB_TVOUT_d_i_26 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_26.dat"
#define AUTOTB_TVIN_d_i_27 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_27.dat"
#define AUTOTB_TVOUT_d_i_27 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_27.dat"
#define AUTOTB_TVIN_d_i_28 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_28.dat"
#define AUTOTB_TVOUT_d_i_28 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_28.dat"
#define AUTOTB_TVIN_d_i_29 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_29.dat"
#define AUTOTB_TVOUT_d_i_29 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_29.dat"
#define AUTOTB_TVIN_d_i_30 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_30.dat"
#define AUTOTB_TVOUT_d_i_30 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_30.dat"
#define AUTOTB_TVIN_d_i_31 "../tv/cdatafile/c.axi_interfaces.autotvin_d_i_31.dat"
#define AUTOTB_TVOUT_d_i_31 "../tv/cdatafile/c.axi_interfaces.autotvout_d_i_31.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_d_o_0 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_0.dat"
#define AUTOTB_TVOUT_PC_d_o_1 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_1.dat"
#define AUTOTB_TVOUT_PC_d_o_2 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_2.dat"
#define AUTOTB_TVOUT_PC_d_o_3 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_3.dat"
#define AUTOTB_TVOUT_PC_d_o_4 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_4.dat"
#define AUTOTB_TVOUT_PC_d_o_5 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_5.dat"
#define AUTOTB_TVOUT_PC_d_o_6 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_6.dat"
#define AUTOTB_TVOUT_PC_d_o_7 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_o_7.dat"
#define AUTOTB_TVOUT_PC_d_i_0 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_0.dat"
#define AUTOTB_TVOUT_PC_d_i_1 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_1.dat"
#define AUTOTB_TVOUT_PC_d_i_2 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_2.dat"
#define AUTOTB_TVOUT_PC_d_i_3 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_3.dat"
#define AUTOTB_TVOUT_PC_d_i_4 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_4.dat"
#define AUTOTB_TVOUT_PC_d_i_5 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_5.dat"
#define AUTOTB_TVOUT_PC_d_i_6 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_6.dat"
#define AUTOTB_TVOUT_PC_d_i_7 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_7.dat"
#define AUTOTB_TVOUT_PC_d_i_8 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_8.dat"
#define AUTOTB_TVOUT_PC_d_i_9 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_9.dat"
#define AUTOTB_TVOUT_PC_d_i_10 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_10.dat"
#define AUTOTB_TVOUT_PC_d_i_11 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_11.dat"
#define AUTOTB_TVOUT_PC_d_i_12 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_12.dat"
#define AUTOTB_TVOUT_PC_d_i_13 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_13.dat"
#define AUTOTB_TVOUT_PC_d_i_14 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_14.dat"
#define AUTOTB_TVOUT_PC_d_i_15 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_15.dat"
#define AUTOTB_TVOUT_PC_d_i_16 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_16.dat"
#define AUTOTB_TVOUT_PC_d_i_17 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_17.dat"
#define AUTOTB_TVOUT_PC_d_i_18 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_18.dat"
#define AUTOTB_TVOUT_PC_d_i_19 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_19.dat"
#define AUTOTB_TVOUT_PC_d_i_20 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_20.dat"
#define AUTOTB_TVOUT_PC_d_i_21 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_21.dat"
#define AUTOTB_TVOUT_PC_d_i_22 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_22.dat"
#define AUTOTB_TVOUT_PC_d_i_23 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_23.dat"
#define AUTOTB_TVOUT_PC_d_i_24 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_24.dat"
#define AUTOTB_TVOUT_PC_d_i_25 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_25.dat"
#define AUTOTB_TVOUT_PC_d_i_26 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_26.dat"
#define AUTOTB_TVOUT_PC_d_i_27 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_27.dat"
#define AUTOTB_TVOUT_PC_d_i_28 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_28.dat"
#define AUTOTB_TVOUT_PC_d_i_29 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_29.dat"
#define AUTOTB_TVOUT_PC_d_i_30 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_30.dat"
#define AUTOTB_TVOUT_PC_d_i_31 "../tv/rtldatafile/rtl.axi_interfaces.autotvout_d_i_31.dat"


static const bool little_endian()
{
  int a = 1;
  return *(char*)&a == 1;
}

inline static void rev_endian(char* p, size_t nbytes)
{
  std::reverse(p, p+nbytes);
}

template<size_t bit_width>
struct transaction {
  typedef uint64_t depth_t;
  static const size_t wbytes = (bit_width+7)>>3;
  static const size_t dbytes = sizeof(depth_t);
  const depth_t depth;
  const size_t vbytes;
  const size_t tbytes;
  char * const p;
  typedef char (*p_dat)[wbytes];
  p_dat vp;

  transaction(depth_t depth)
    : depth(depth), vbytes(wbytes*depth), tbytes(dbytes+vbytes),
      p(new char[tbytes]) {
    *(depth_t*)p = depth;
    rev_endian(p, dbytes);
    vp = (p_dat) (p+dbytes);
  }

  void reorder() {
    rev_endian(p, dbytes);
    p_dat vp = (p_dat) (p+dbytes);
    for (depth_t i = 0; i < depth; ++i) {
      rev_endian(vp[i], wbytes);
    }
  }

  template<size_t psize>
  void import(char* param, depth_t num, int64_t offset) {
    param -= offset*psize;
    for (depth_t i = 0; i < num; ++i) {
      memcpy(vp[i], param, wbytes);
      param += psize;
      if (little_endian()) {
        rev_endian(vp[i], wbytes);
      }
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[i], wbytes);
      param += psize;
    }
    vp += num;
  }

  template<size_t psize>
  void send(char* param, depth_t num, int64_t skip) {
    for (depth_t i = 0; i < num; ++i) {
      memcpy(param, vp[skip+i], wbytes);
      param += psize;
    }
  }

  ~transaction() { if (p) { delete[] p; } }
};


inline static const std::string begin_str(int num)
{
  return std::string("[[transaction]]           ")
         .append(std::to_string(num))
         .append("\n");
}

inline static const std::string end_str()
{
  return std::string("[[/transaction]]\n");
}

const std::string formatData(unsigned char *pos, size_t wbits)
{
  bool LE = little_endian();
  size_t wbytes = (wbits+7)>>3;
  size_t i = LE ? wbytes-1 : 0;
  auto next = [&] () {
    auto c = pos[i];
    LE ? --i : ++i;
    return c;
  };
  std::ostringstream ss;
  ss << "0x";
  if (int t = (wbits & 0x7)) {
    if (t <= 4) {
      unsigned char mask = (1<<t)-1;
      ss << std::hex << std::setfill('0') << std::setw(1)
         << (int) (next() & mask);
      wbytes -= 1;
    }
  }
  for (size_t i = 0; i < wbytes; ++i) {
    ss << std::hex << std::setfill('0') << std::setw(2) << (int)next();
  }
  ss.put('\n');
  return ss.str();
}

static bool RTLOutputCheckAndReplacement(std::string &data)
{
  bool changed = false;
  for (size_t i = 2; i < data.size(); ++i) {
    if (data[i] == 'X' || data[i] == 'x') {
      data[i] = '0';
      changed = true;
    }
  }
  return changed;
}

struct SimException : public std::exception {
  const char *msg;
  const size_t line;
  SimException(const char *msg, const size_t line)
    : msg(msg), line(line)
  {
  }
};

template<size_t bit_width>
class PostCheck
{
  static const char *bad;
  static const char *err;
  std::fstream stream;
  std::string s;

  void send(char *p, ap_uint<bit_width> &data, size_t l, size_t rest)
  {
    if (rest == 0) {
      if (!little_endian()) {
        const size_t wbytes = (bit_width+7)>>3;
        rev_endian(p-wbytes, wbytes);
      }
    } else if (rest < 8) {
      *p = data.range(l+rest-1, l).to_uint();
      send(p+1, data, l+rest, 0);
    } else {
      *p = data.range(l+8-1, l).to_uint();
      send(p+1, data, l+8, rest-8);
    }
  }

  void readline()
  {
    std::getline(stream, s);
    if (stream.eof()) {
      throw SimException(bad, __LINE__);
    }
  }

public:
  char *param;
  size_t psize;
  size_t depth;

  PostCheck(const char *file)
  {
    stream.open(file);
    if (stream.fail()) {
      throw SimException(err, __LINE__);
    } else {
      readline();
      if (s != "[[[runtime]]]") {
        throw SimException(bad, __LINE__);
      }
    }
  }

  ~PostCheck() noexcept(false)
  {
    stream.close();
  }

  void run(size_t AESL_transaction_pc, size_t skip)
  {
    if (stream.peek() == '[') {
      readline();
    }

    for (size_t i = 0; i < skip; ++i) {
      readline();
    }

    bool foundX = false;
    for (size_t i = 0; i < depth; ++i) {
      readline();
      foundX |= RTLOutputCheckAndReplacement(s);
      ap_uint<bit_width> data(s.c_str(), 16);
      send(param+i*psize, data, 0, bit_width);
    }
    if (foundX) {
      std::cerr << "WARNING: [SIM 212-201] RTL produces unknown value "
                << "'x' or 'X' on some port, possible cause: "
                << "There are uninitialized variables in the design.\n";
    }

    if (stream.peek() == '[') {
      readline();
    }
  }
};

template<size_t bit_width>
const char* PostCheck<bit_width>::bad = "Bad TV file";

template<size_t bit_width>
const char* PostCheck<bit_width>::err = "Error on TV file";
      
class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  d_o_0_depth = 0;
  d_o_1_depth = 0;
  d_o_2_depth = 0;
  d_o_3_depth = 0;
  d_o_4_depth = 0;
  d_o_5_depth = 0;
  d_o_6_depth = 0;
  d_o_7_depth = 0;
  d_i_0_depth = 0;
  d_i_1_depth = 0;
  d_i_2_depth = 0;
  d_i_3_depth = 0;
  d_i_4_depth = 0;
  d_i_5_depth = 0;
  d_i_6_depth = 0;
  d_i_7_depth = 0;
  d_i_8_depth = 0;
  d_i_9_depth = 0;
  d_i_10_depth = 0;
  d_i_11_depth = 0;
  d_i_12_depth = 0;
  d_i_13_depth = 0;
  d_i_14_depth = 0;
  d_i_15_depth = 0;
  d_i_16_depth = 0;
  d_i_17_depth = 0;
  d_i_18_depth = 0;
  d_i_19_depth = 0;
  d_i_20_depth = 0;
  d_i_21_depth = 0;
  d_i_22_depth = 0;
  d_i_23_depth = 0;
  d_i_24_depth = 0;
  d_i_25_depth = 0;
  d_i_26_depth = 0;
  d_i_27_depth = 0;
  d_i_28_depth = 0;
  d_i_29_depth = 0;
  d_i_30_depth = 0;
  d_i_31_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{d_o_0 " << d_o_0_depth << "}\n";
  total_list << "{d_o_1 " << d_o_1_depth << "}\n";
  total_list << "{d_o_2 " << d_o_2_depth << "}\n";
  total_list << "{d_o_3 " << d_o_3_depth << "}\n";
  total_list << "{d_o_4 " << d_o_4_depth << "}\n";
  total_list << "{d_o_5 " << d_o_5_depth << "}\n";
  total_list << "{d_o_6 " << d_o_6_depth << "}\n";
  total_list << "{d_o_7 " << d_o_7_depth << "}\n";
  total_list << "{d_i_0 " << d_i_0_depth << "}\n";
  total_list << "{d_i_1 " << d_i_1_depth << "}\n";
  total_list << "{d_i_2 " << d_i_2_depth << "}\n";
  total_list << "{d_i_3 " << d_i_3_depth << "}\n";
  total_list << "{d_i_4 " << d_i_4_depth << "}\n";
  total_list << "{d_i_5 " << d_i_5_depth << "}\n";
  total_list << "{d_i_6 " << d_i_6_depth << "}\n";
  total_list << "{d_i_7 " << d_i_7_depth << "}\n";
  total_list << "{d_i_8 " << d_i_8_depth << "}\n";
  total_list << "{d_i_9 " << d_i_9_depth << "}\n";
  total_list << "{d_i_10 " << d_i_10_depth << "}\n";
  total_list << "{d_i_11 " << d_i_11_depth << "}\n";
  total_list << "{d_i_12 " << d_i_12_depth << "}\n";
  total_list << "{d_i_13 " << d_i_13_depth << "}\n";
  total_list << "{d_i_14 " << d_i_14_depth << "}\n";
  total_list << "{d_i_15 " << d_i_15_depth << "}\n";
  total_list << "{d_i_16 " << d_i_16_depth << "}\n";
  total_list << "{d_i_17 " << d_i_17_depth << "}\n";
  total_list << "{d_i_18 " << d_i_18_depth << "}\n";
  total_list << "{d_i_19 " << d_i_19_depth << "}\n";
  total_list << "{d_i_20 " << d_i_20_depth << "}\n";
  total_list << "{d_i_21 " << d_i_21_depth << "}\n";
  total_list << "{d_i_22 " << d_i_22_depth << "}\n";
  total_list << "{d_i_23 " << d_i_23_depth << "}\n";
  total_list << "{d_i_24 " << d_i_24_depth << "}\n";
  total_list << "{d_i_25 " << d_i_25_depth << "}\n";
  total_list << "{d_i_26 " << d_i_26_depth << "}\n";
  total_list << "{d_i_27 " << d_i_27_depth << "}\n";
  total_list << "{d_i_28 " << d_i_28_depth << "}\n";
  total_list << "{d_i_29 " << d_i_29_depth << "}\n";
  total_list << "{d_i_30 " << d_i_30_depth << "}\n";
  total_list << "{d_i_31 " << d_i_31_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int d_o_0_depth;
    int d_o_1_depth;
    int d_o_2_depth;
    int d_o_3_depth;
    int d_o_4_depth;
    int d_o_5_depth;
    int d_o_6_depth;
    int d_o_7_depth;
    int d_i_0_depth;
    int d_i_1_depth;
    int d_i_2_depth;
    int d_i_3_depth;
    int d_i_4_depth;
    int d_i_5_depth;
    int d_i_6_depth;
    int d_i_7_depth;
    int d_i_8_depth;
    int d_i_9_depth;
    int d_i_10_depth;
    int d_i_11_depth;
    int d_i_12_depth;
    int d_i_13_depth;
    int d_i_14_depth;
    int d_i_15_depth;
    int d_i_16_depth;
    int d_i_17_depth;
    int d_i_18_depth;
    int d_i_19_depth;
    int d_i_20_depth;
    int d_i_21_depth;
    int d_i_22_depth;
    int d_i_23_depth;
    int d_i_24_depth;
    int d_i_25_depth;
    int d_i_26_depth;
    int d_i_27_depth;
    int d_i_28_depth;
    int d_i_29_depth;
    int d_i_30_depth;
    int d_i_31_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};


extern "C" void axi_interfaces_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_axi_interfaces_hw(volatile void * __xlx_apatb_param_d_o_0, volatile void * __xlx_apatb_param_d_o_1, volatile void * __xlx_apatb_param_d_o_2, volatile void * __xlx_apatb_param_d_o_3, volatile void * __xlx_apatb_param_d_o_4, volatile void * __xlx_apatb_param_d_o_5, volatile void * __xlx_apatb_param_d_o_6, volatile void * __xlx_apatb_param_d_o_7, volatile void * __xlx_apatb_param_d_i_0, volatile void * __xlx_apatb_param_d_i_1, volatile void * __xlx_apatb_param_d_i_2, volatile void * __xlx_apatb_param_d_i_3, volatile void * __xlx_apatb_param_d_i_4, volatile void * __xlx_apatb_param_d_i_5, volatile void * __xlx_apatb_param_d_i_6, volatile void * __xlx_apatb_param_d_i_7, volatile void * __xlx_apatb_param_d_i_8, volatile void * __xlx_apatb_param_d_i_9, volatile void * __xlx_apatb_param_d_i_10, volatile void * __xlx_apatb_param_d_i_11, volatile void * __xlx_apatb_param_d_i_12, volatile void * __xlx_apatb_param_d_i_13, volatile void * __xlx_apatb_param_d_i_14, volatile void * __xlx_apatb_param_d_i_15, volatile void * __xlx_apatb_param_d_i_16, volatile void * __xlx_apatb_param_d_i_17, volatile void * __xlx_apatb_param_d_i_18, volatile void * __xlx_apatb_param_d_i_19, volatile void * __xlx_apatb_param_d_i_20, volatile void * __xlx_apatb_param_d_i_21, volatile void * __xlx_apatb_param_d_i_22, volatile void * __xlx_apatb_param_d_i_23, volatile void * __xlx_apatb_param_d_i_24, volatile void * __xlx_apatb_param_d_i_25, volatile void * __xlx_apatb_param_d_i_26, volatile void * __xlx_apatb_param_d_i_27, volatile void * __xlx_apatb_param_d_i_28, volatile void * __xlx_apatb_param_d_i_29, volatile void * __xlx_apatb_param_d_i_30, volatile void * __xlx_apatb_param_d_i_31) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
static AESL_FILE_HANDLER aesl_fh;
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;
{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_0_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_0_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_0" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_0)[j*2+0] = d_o_0_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_0)[j*2+1] = d_o_0_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_1_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_1" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_1)[j*2+0] = d_o_1_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_1)[j*2+1] = d_o_1_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_2_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_2_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_2" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_2)[j*2+0] = d_o_2_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_2)[j*2+1] = d_o_2_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_3);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_3_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_3_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_3" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_3)[j*2+0] = d_o_3_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_3)[j*2+1] = d_o_3_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_4);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_4_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_4_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_4" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_4)[j*2+0] = d_o_4_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_4)[j*2+1] = d_o_4_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_5);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_5_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_5_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_5" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_5)[j*2+0] = d_o_5_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_5)[j*2+1] = d_o_5_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_6);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_6_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_6_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_6" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_6)[j*2+0] = d_o_6_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_6)[j*2+1] = d_o_6_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_o_7);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_o_7_pc_buffer(4);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_o_7_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_o_7" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 4; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_o_7)[j*2+0] = d_o_7_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_o_7)[j*2+1] = d_o_7_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_0);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_0_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_0_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_0" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_0)[j*2+0] = d_i_0_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_0)[j*2+1] = d_i_0_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_1);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_1_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_1_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_1" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_1)[j*2+0] = d_i_1_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_1)[j*2+1] = d_i_1_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_2);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_2_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_2_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_2" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_2)[j*2+0] = d_i_2_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_2)[j*2+1] = d_i_2_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_3);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_3_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_3_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_3" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_3)[j*2+0] = d_i_3_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_3)[j*2+1] = d_i_3_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_4);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_4_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_4_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_4" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_4)[j*2+0] = d_i_4_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_4)[j*2+1] = d_i_4_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_5);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_5_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_5_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_5" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_5)[j*2+0] = d_i_5_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_5)[j*2+1] = d_i_5_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_6);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_6_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_6_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_6" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_6)[j*2+0] = d_i_6_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_6)[j*2+1] = d_i_6_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_7);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_7_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_7_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_7" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_7)[j*2+0] = d_i_7_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_7)[j*2+1] = d_i_7_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_8);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_8_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_8_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_8" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_8)[j*2+0] = d_i_8_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_8)[j*2+1] = d_i_8_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_9);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_9_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_9_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_9" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_9)[j*2+0] = d_i_9_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_9)[j*2+1] = d_i_9_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_10);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_10_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_10_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_10" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_10)[j*2+0] = d_i_10_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_10)[j*2+1] = d_i_10_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_11);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_11_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_11_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_11" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_11)[j*2+0] = d_i_11_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_11)[j*2+1] = d_i_11_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_12);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_12_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_12_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_12" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_12)[j*2+0] = d_i_12_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_12)[j*2+1] = d_i_12_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_13);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_13_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_13_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_13" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_13)[j*2+0] = d_i_13_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_13)[j*2+1] = d_i_13_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_14);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_14_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_14_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_14" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_14)[j*2+0] = d_i_14_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_14)[j*2+1] = d_i_14_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_15);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_15_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_15_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_15" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_15)[j*2+0] = d_i_15_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_15)[j*2+1] = d_i_15_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_16);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_16_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_16_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_16" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_16)[j*2+0] = d_i_16_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_16)[j*2+1] = d_i_16_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_17);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_17_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_17_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_17" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_17)[j*2+0] = d_i_17_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_17)[j*2+1] = d_i_17_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_18);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_18_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_18_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_18" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_18)[j*2+0] = d_i_18_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_18)[j*2+1] = d_i_18_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_19);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_19_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_19_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_19" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_19)[j*2+0] = d_i_19_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_19)[j*2+1] = d_i_19_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_20);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_20_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_20_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_20" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_20)[j*2+0] = d_i_20_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_20)[j*2+1] = d_i_20_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_21);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_21_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_21_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_21" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_21)[j*2+0] = d_i_21_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_21)[j*2+1] = d_i_21_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_22);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_22_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_22_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_22" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_22)[j*2+0] = d_i_22_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_22)[j*2+1] = d_i_22_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_23);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_23_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_23_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_23" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_23)[j*2+0] = d_i_23_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_23)[j*2+1] = d_i_23_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_24);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_24_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_24_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_24" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_24)[j*2+0] = d_i_24_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_24)[j*2+1] = d_i_24_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_25);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_25_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_25_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_25" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_25)[j*2+0] = d_i_25_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_25)[j*2+1] = d_i_25_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_26);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_26_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_26_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_26" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_26)[j*2+0] = d_i_26_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_26)[j*2+1] = d_i_26_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_27);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_27_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_27_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_27" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_27)[j*2+0] = d_i_27_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_27)[j*2+1] = d_i_27_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_28);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_28_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_28_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_28" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_28)[j*2+0] = d_i_28_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_28)[j*2+1] = d_i_28_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_29);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_29_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_29_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_29" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_29)[j*2+0] = d_i_29_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_29)[j*2+1] = d_i_29_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_30);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_30_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_30_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_30" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_30)[j*2+0] = d_i_30_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_30)[j*2+1] = d_i_30_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  {
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_d_i_31);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<16> > d_i_31_pc_buffer(1);
          int i = 0;
          bool has_unknown_value = false;
          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            has_unknown_value |= RTLOutputCheckAndReplacement(AESL_token);
  
            // push token into output port buffer
            if (AESL_token != "") {
              d_i_31_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (has_unknown_value) {
            cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' or 'X' on port " 
                 << "d_i_31" << ", possible cause: There are uninitialized variables in the C design."
                 << endl; 
          }
  
          if (i > 0) {{
		    int i = 0;
            for (int j = 0, e = 1; j < e; j += 1, ++i) {((char*)__xlx_apatb_param_d_i_31)[j*2+0] = d_i_31_pc_buffer[i].range(7, 0).to_int64();
((char*)__xlx_apatb_param_d_i_31)[j*2+1] = d_i_31_pc_buffer[i].range(15, 8).to_int64();
}}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
CodeState = DUMP_INPUTS;
// print d_o_0 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_0, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_0) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_0+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_0, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_0_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_0, end_str());
}

// print d_o_1 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_1, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_1) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_1+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_1, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_1_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_1, end_str());
}

// print d_o_2 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_2, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_2) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_2+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_2, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_2_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_2, end_str());
}

// print d_o_3 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_3, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_3) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_3+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_3, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_3_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_3, end_str());
}

// print d_o_4 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_4, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_4) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_4+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_4, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_4_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_4, end_str());
}

// print d_o_5 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_5, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_5) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_5+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_5, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_5_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_5, end_str());
}

// print d_o_6 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_6, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_6) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_6+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_6, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_6_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_6, end_str());
}

// print d_o_7 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_o_7, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_7) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_7+i*2;
aesl_fh.write(AUTOTB_TVIN_d_o_7, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_7_depth);
aesl_fh.write(AUTOTB_TVIN_d_o_7, end_str());
}

// print d_i_0 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_0, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_0) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_0+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_0, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_0_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_0, end_str());
}

// print d_i_1 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_1, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_1) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_1+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_1, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_1_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_1, end_str());
}

// print d_i_2 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_2, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_2) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_2+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_2, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_2_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_2, end_str());
}

// print d_i_3 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_3, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_3) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_3+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_3, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_3_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_3, end_str());
}

// print d_i_4 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_4, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_4) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_4+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_4, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_4_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_4, end_str());
}

// print d_i_5 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_5, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_5) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_5+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_5, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_5_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_5, end_str());
}

// print d_i_6 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_6, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_6) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_6+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_6, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_6_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_6, end_str());
}

// print d_i_7 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_7, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_7) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_7+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_7, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_7_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_7, end_str());
}

// print d_i_8 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_8, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_8) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_8+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_8, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_8_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_8, end_str());
}

// print d_i_9 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_9, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_9) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_9+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_9, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_9_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_9, end_str());
}

// print d_i_10 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_10, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_10) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_10+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_10, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_10_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_10, end_str());
}

// print d_i_11 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_11, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_11) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_11+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_11, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_11_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_11, end_str());
}

// print d_i_12 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_12, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_12) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_12+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_12, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_12_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_12, end_str());
}

// print d_i_13 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_13, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_13) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_13+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_13, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_13_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_13, end_str());
}

// print d_i_14 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_14, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_14) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_14+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_14, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_14_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_14, end_str());
}

// print d_i_15 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_15, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_15) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_15+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_15, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_15_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_15, end_str());
}

// print d_i_16 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_16, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_16) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_16+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_16, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_16_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_16, end_str());
}

// print d_i_17 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_17, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_17) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_17+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_17, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_17_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_17, end_str());
}

// print d_i_18 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_18, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_18) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_18+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_18, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_18_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_18, end_str());
}

// print d_i_19 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_19, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_19) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_19+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_19, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_19_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_19, end_str());
}

// print d_i_20 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_20, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_20) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_20+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_20, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_20_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_20, end_str());
}

// print d_i_21 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_21, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_21) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_21+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_21, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_21_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_21, end_str());
}

// print d_i_22 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_22, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_22) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_22+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_22, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_22_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_22, end_str());
}

// print d_i_23 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_23, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_23) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_23+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_23, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_23_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_23, end_str());
}

// print d_i_24 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_24, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_24) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_24+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_24, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_24_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_24, end_str());
}

// print d_i_25 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_25, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_25) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_25+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_25, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_25_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_25, end_str());
}

// print d_i_26 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_26, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_26) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_26+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_26, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_26_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_26, end_str());
}

// print d_i_27 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_27, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_27) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_27+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_27, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_27_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_27, end_str());
}

// print d_i_28 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_28, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_28) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_28+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_28, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_28_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_28, end_str());
}

// print d_i_29 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_29, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_29) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_29+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_29, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_29_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_29, end_str());
}

// print d_i_30 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_30, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_30) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_30+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_30, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_30_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_30, end_str());
}

// print d_i_31 Transactions
{
aesl_fh.write(AUTOTB_TVIN_d_i_31, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_31) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_31+i*2;
aesl_fh.write(AUTOTB_TVIN_d_i_31, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_31_depth);
aesl_fh.write(AUTOTB_TVIN_d_i_31, end_str());
}

CodeState = CALL_C_DUT;
axi_interfaces_hw_stub_wrapper(__xlx_apatb_param_d_o_0, __xlx_apatb_param_d_o_1, __xlx_apatb_param_d_o_2, __xlx_apatb_param_d_o_3, __xlx_apatb_param_d_o_4, __xlx_apatb_param_d_o_5, __xlx_apatb_param_d_o_6, __xlx_apatb_param_d_o_7, __xlx_apatb_param_d_i_0, __xlx_apatb_param_d_i_1, __xlx_apatb_param_d_i_2, __xlx_apatb_param_d_i_3, __xlx_apatb_param_d_i_4, __xlx_apatb_param_d_i_5, __xlx_apatb_param_d_i_6, __xlx_apatb_param_d_i_7, __xlx_apatb_param_d_i_8, __xlx_apatb_param_d_i_9, __xlx_apatb_param_d_i_10, __xlx_apatb_param_d_i_11, __xlx_apatb_param_d_i_12, __xlx_apatb_param_d_i_13, __xlx_apatb_param_d_i_14, __xlx_apatb_param_d_i_15, __xlx_apatb_param_d_i_16, __xlx_apatb_param_d_i_17, __xlx_apatb_param_d_i_18, __xlx_apatb_param_d_i_19, __xlx_apatb_param_d_i_20, __xlx_apatb_param_d_i_21, __xlx_apatb_param_d_i_22, __xlx_apatb_param_d_i_23, __xlx_apatb_param_d_i_24, __xlx_apatb_param_d_i_25, __xlx_apatb_param_d_i_26, __xlx_apatb_param_d_i_27, __xlx_apatb_param_d_i_28, __xlx_apatb_param_d_i_29, __xlx_apatb_param_d_i_30, __xlx_apatb_param_d_i_31);
CodeState = DUMP_OUTPUTS;
// print d_o_0 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_0, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_0) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_0+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_0, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_0_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_0, end_str());
}

// print d_o_1 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_1, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_1) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_1+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_1, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_1_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_1, end_str());
}

// print d_o_2 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_2, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_2) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_2+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_2, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_2_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_2, end_str());
}

// print d_o_3 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_3, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_3) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_3+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_3, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_3_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_3, end_str());
}

// print d_o_4 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_4, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_4) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_4+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_4, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_4_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_4, end_str());
}

// print d_o_5 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_5, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_5) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_5+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_5, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_5_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_5, end_str());
}

// print d_o_6 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_6, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_6) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_6+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_6, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_6_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_6, end_str());
}

// print d_o_7 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_o_7, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_o_7) {
for (int i = 0; i < 4; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_o_7+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_o_7, formatData(pos, 16));
}
}

  tcl_file.set_num(4, &tcl_file.d_o_7_depth);
aesl_fh.write(AUTOTB_TVOUT_d_o_7, end_str());
}

// print d_i_0 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_0, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_0) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_0+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_0, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_0_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_0, end_str());
}

// print d_i_1 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_1, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_1) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_1+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_1, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_1_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_1, end_str());
}

// print d_i_2 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_2, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_2) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_2+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_2, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_2_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_2, end_str());
}

// print d_i_3 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_3, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_3) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_3+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_3, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_3_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_3, end_str());
}

// print d_i_4 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_4, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_4) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_4+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_4, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_4_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_4, end_str());
}

// print d_i_5 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_5, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_5) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_5+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_5, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_5_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_5, end_str());
}

// print d_i_6 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_6, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_6) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_6+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_6, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_6_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_6, end_str());
}

// print d_i_7 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_7, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_7) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_7+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_7, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_7_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_7, end_str());
}

// print d_i_8 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_8, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_8) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_8+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_8, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_8_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_8, end_str());
}

// print d_i_9 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_9, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_9) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_9+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_9, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_9_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_9, end_str());
}

// print d_i_10 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_10, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_10) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_10+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_10, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_10_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_10, end_str());
}

// print d_i_11 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_11, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_11) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_11+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_11, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_11_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_11, end_str());
}

// print d_i_12 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_12, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_12) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_12+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_12, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_12_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_12, end_str());
}

// print d_i_13 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_13, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_13) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_13+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_13, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_13_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_13, end_str());
}

// print d_i_14 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_14, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_14) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_14+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_14, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_14_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_14, end_str());
}

// print d_i_15 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_15, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_15) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_15+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_15, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_15_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_15, end_str());
}

// print d_i_16 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_16, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_16) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_16+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_16, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_16_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_16, end_str());
}

// print d_i_17 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_17, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_17) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_17+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_17, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_17_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_17, end_str());
}

// print d_i_18 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_18, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_18) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_18+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_18, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_18_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_18, end_str());
}

// print d_i_19 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_19, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_19) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_19+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_19, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_19_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_19, end_str());
}

// print d_i_20 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_20, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_20) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_20+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_20, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_20_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_20, end_str());
}

// print d_i_21 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_21, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_21) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_21+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_21, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_21_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_21, end_str());
}

// print d_i_22 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_22, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_22) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_22+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_22, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_22_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_22, end_str());
}

// print d_i_23 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_23, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_23) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_23+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_23, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_23_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_23, end_str());
}

// print d_i_24 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_24, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_24) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_24+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_24, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_24_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_24, end_str());
}

// print d_i_25 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_25, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_25) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_25+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_25, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_25_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_25, end_str());
}

// print d_i_26 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_26, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_26) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_26+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_26, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_26_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_26, end_str());
}

// print d_i_27 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_27, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_27) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_27+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_27, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_27_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_27, end_str());
}

// print d_i_28 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_28, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_28) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_28+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_28, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_28_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_28, end_str());
}

// print d_i_29 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_29, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_29) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_29+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_29, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_29_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_29, end_str());
}

// print d_i_30 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_30, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_30) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_30+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_30, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_30_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_30, end_str());
}

// print d_i_31 Transactions
{
aesl_fh.write(AUTOTB_TVOUT_d_i_31, begin_str(AESL_transaction));
if (__xlx_apatb_param_d_i_31) {
for (int i = 0; i < 1; ++i) {
auto *pos = (unsigned char*)__xlx_apatb_param_d_i_31+i*2;
aesl_fh.write(AUTOTB_TVOUT_d_i_31, formatData(pos, 16));
}
}

  tcl_file.set_num(1, &tcl_file.d_i_31_depth);
aesl_fh.write(AUTOTB_TVOUT_d_i_31, end_str());
}

CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
