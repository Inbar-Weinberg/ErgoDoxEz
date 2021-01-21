
// update for Qmk
// git fetch upstream
// git merge upstream

/* code for compiling 
 * cd  /C/Users/Inbar/Desktop/Tools/qmk_firmware
 * make ergodox_ez:Math
*/

#include QMK_KEYBOARD_H
#include "version.h"


#define KC_REDO LCTL(KC_Y)
#define KC_UNDO LCTL(KC_Z)
#define KC_CUT LCTL(KC_X)
#define KC_COPY LCTL(KC_C)
#define KC_PASTE LCTL(KC_V)
#define KC_LANGUAGE LALT(LSFT(KC_NO))

#define KC_NUM_SIGN LSFT(KC_3)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define ___ KC_TRANSPARENT
#define XXX KC_NO
#define PRINT_SCREEN LGUI(KC_PSCREEN)
#define PRINT_SCREEN2 LGUI(LSFT(KC_S))


enum custom_keycodes { // Macros Declarations
  RGB_SLD = EZ_SAFE_RANGE,

  ST_MACRO_8, // Math Type Layer on
  ST_MACRO_9, // Math Type Layer off
  Inf_Macro_Math, //Infinity on Math Type
  Pi_Macro_Math, // Pi on  Math Type
  
  /*
  ST_MACRO_12, // Hebrew + Hebrew Layer
  ST_MACRO_13, // Hebrew + Hebrew Layer
  ST_MACRO_14, // OSM control + osl 1
  */
};


enum {  // Tap Dance Declarations
   TD_alttab = 0,  TD_copy  
  ,TD_a  ,TD_b  ,TD_c  ,TD_d  ,TD_e  ,TD_f  ,TD_g  ,TD_h  ,TD_i  ,TD_j  ,TD_k  ,TD_l  ,TD_m  ,TD_n  ,TD_o  ,TD_p  ,TD_q  ,TD_r  ,TD_s  ,TD_t  ,TD_u  ,TD_v  ,TD_w  ,TD_x  ,TD_y  ,TD_z
  ,TD_QUES  ,TD_EXLM ,TD_ASTR , TD_CIRC, TD_SCOLON, TD_COLON ,TD_UNDS , TD_MINUS, TD_EQUAL2 , TD_PLUS , TD_DQUO , TD_TILD , TD_PERC , TD_SLASH , TD_BSLASH , TD_QUOTE
  
  ,TD_LABK  ,TD_RABK  ,TD_LPRN  ,TD_RPRN ,TD_LBRACKET  ,TD_RBRACKET ,TD_LCBR  ,TD_RCBR ,TD_PIPE
  ,TD_n0  ,TD_n1  ,TD_n2  ,TD_n3 ,TD_n4  ,TD_n5 ,TD_n6 ,TD_n7 ,TD_n8  ,TD_n9
  ,TD_B  ,TD_M  ,TD_N  ,TD_P ,TD_F  
  ,TD_comma ,TD_dot
  /*
  ,TD_equal,  TD_less_equal,  TD_great_equal
  */
  };


typedef enum { // for advanced Tap Dance
// General
  alttab_TAP1 = 1,  alttab_TAP2 = 2,
  copy_TAP1= 1,  copy_TAP2= 2,

//Math Type Base
  a_TAP1= 1,  a_HOLD1= 2,  a_TAP2= 3,  a_HOLD2= 4,
  b_TAP1= 1,  b_HOLD1= 2,  b_TAP2= 3,  b_HOLD2= 4,
  c_TAP1= 1,  c_HOLD1= 2,  c_TAP2= 3,  c_HOLD2= 4,
  d_TAP1= 1,  d_HOLD1= 2,  d_TAP2= 3,  d_HOLD2= 4,
  e_TAP1= 1,  e_HOLD1= 2,  e_TAP2= 3,  e_HOLD2= 4,
  f_TAP1= 1,  f_HOLD1= 2,  f_TAP2= 3,  f_HOLD2= 4,
  g_TAP1= 1,  g_HOLD1= 2,  g_TAP2= 3,  g_HOLD2= 4,
  h_TAP1= 1,  h_HOLD1= 2,  h_TAP2= 3,  h_HOLD2= 4,
  i_TAP1= 1,  i_HOLD1= 2,  i_TAP2= 3,  i_HOLD2= 4,
  j_TAP1= 1,  j_HOLD1= 2,  j_TAP2= 3,  j_HOLD2= 4,
  k_TAP1= 1,  k_HOLD1= 2,  k_TAP2= 3,  k_HOLD2= 4,
  l_TAP1= 1,  l_HOLD1= 2,  l_TAP2= 3,  l_HOLD2= 4,
  m_TAP1= 1,  m_HOLD1= 2,  m_TAP2= 3,  m_HOLD2= 4,
  n_TAP1= 1,  n_HOLD1= 2,  n_TAP2= 3,  n_HOLD2= 4,
  o_TAP1= 1,  o_HOLD1= 2,  o_TAP2= 3,  o_HOLD2= 4,
  p_TAP1= 1,  p_HOLD1= 2,  p_TAP2= 3,  p_HOLD2= 4,
  q_TAP1= 1,  q_HOLD1= 2,  q_TAP2= 3,  q_HOLD2= 4,
  r_TAP1= 1,  r_HOLD1= 2,  r_TAP2= 3,  r_HOLD2= 4,
  s_TAP1= 1,  s_HOLD1= 2,  s_TAP2= 3,  s_HOLD2= 4,
  t_TAP1= 1,  t_HOLD1= 2,  t_TAP2= 3,  t_HOLD2= 4,
  u_TAP1= 1,  u_HOLD1= 2,  u_TAP2= 3,  u_HOLD2= 4,
  v_TAP1= 1,  v_HOLD1= 2,  v_TAP2= 3,  v_HOLD2= 4,
  w_TAP1= 1,  w_HOLD1= 2,  w_TAP2= 3,  w_HOLD2= 4,
  x_TAP1= 1,  x_HOLD1= 2,  x_TAP2= 3,  x_HOLD2= 4,
  y_TAP1= 1,  y_HOLD1= 2,  y_TAP2= 3,  y_HOLD2= 4,
  z_TAP1= 1,  z_HOLD1= 2,  z_TAP2= 3,  z_HOLD2= 4,
  comma_TAP1= 1,  comma_HOLD1= 2,  comma_TAP2= 3,  comma_HOLD2= 4,
  dot_TAP1= 1,  dot_HOLD1= 2,  dot_TAP2= 3,  dot_HOLD2= 4,

//Math Type Math Symboles
  QUES_TAP1= 1,  QUES_HOLD1= 2,  QUES_TAP2= 3,
  EXLM_TAP1= 1,  EXLM_HOLD1= 2,  EXLM_TAP2= 3,
  ASTR_TAP1= 1,  ASTR_HOLD1= 2,  ASTR_TAP2= 3,
  CIRC_TAP1= 1,  CIRC_HOLD1= 2,  CIRC_TAP2= 3,
  SCOLON_TAP1= 1,  SCOLON_HOLD1= 2,  SCOLON_TAP2= 3,
  UNDS_TAP1= 1,  UNDS_HOLD1= 2,  UNDS_TAP2= 3,
  MINUS_TAP1= 1,  MINUS_HOLD1= 2,  MINUS_TAP2= 3,
  EQUAL2_TAP1= 1,  EQUAL2_HOLD1= 2,  EQUAL2_TAP2= 3,
  PLUS_TAP1= 1,  PLUS_HOLD1= 2,  PLUS_TAP2= 3,
  DQUO_TAP1= 1,  DQUO_HOLD1= 2,  DQUO_TAP2= 3,
  TILD_TAP1= 1,  TILD_HOLD1= 2,  TILD_TAP2= 3,
  PERC_TAP1= 1,  PERC_HOLD1= 2,  PERC_TAP2= 3,
  SLASH_TAP1= 1,  SLASH_HOLD1= 2,  SLASH_TAP2= 3,
  BSLASH_TAP1= 1,  BSLASH_HOLD1= 2,  BSLASH_TAP2= 3,
  QUOTE_TAP1= 1,  QUOTE_HOLD1= 2,  QUOTE_TAP2= 3,
  COLON_TAP1= 1,  COLON_HOLD1= 2,  COLON_TAP2= 3,
  
//Math Type Brackets
  LABK_TAP1= 1,  LABK_HOLD1= 2,  LABK_TAP2= 3,
  RABK_TAP1= 1,  RABK_HOLD1= 2,  RABK_TAP2= 3,
  LPRN_TAP1= 1,  LPRN_HOLD1= 2,  LPRN_TAP2= 3,
  RPRN_TAP1= 1,  RPRN_HOLD1= 2,  RPRN_TAP2= 3,
  LBRACKET_TAP1= 1,  LBRACKET_HOLD1= 2,  LBRACKET_TAP2= 3,
  RBRACKET_TAP1= 1,  RBRACKET_HOLD1= 2,  RBRACKET_TAP2= 3,
  LCBR_TAP1= 1,  LCBR_HOLD1= 2,  LCBR_TAP2= 3,
  RCBR_TAP1= 1,  RCBR_HOLD1= 2,  RCBR_TAP2= 3,
  PIPE_TAP1= 1,  PIPE_HOLD1= 2,  PIPE_TAP2= 3,

// Hebrew last letters
  B_TAP1= 1,  B_HOLD1= 2,
  M_TAP1= 1,  M_HOLD1= 2,
  N_TAP1= 1,  N_HOLD1= 2,
  P_TAP1= 1,  P_HOLD1= 2,
  F_TAP1= 1,  F_HOLD1= 2,
  
//Math Type Numbers
  n0_TAP1= 1,  n0_HOLD1= 2,  n0_TAP2= 3,
  n1_TAP1= 1,  n1_HOLD1= 2,  n1_TAP2= 3,
  n2_TAP1= 1,  n2_HOLD1= 2,  n2_TAP2= 3,
  n3_TAP1= 1,  n3_HOLD1= 2,  n3_TAP2= 3,
  n4_TAP1= 1,  n4_HOLD1= 2,  n4_TAP2= 3,
  n5_TAP1= 1,  n5_HOLD1= 2,  n5_TAP2= 3,
  n6_TAP1= 1,  n6_HOLD1= 2,  n6_TAP2= 3,
  n7_TAP1= 1,  n7_HOLD1= 2,  n7_TAP2= 3,
  n8_TAP1= 1,  n8_HOLD1= 2,  n8_TAP2= 3,
  n9_TAP1= 1,  n9_HOLD1= 2,  n9_TAP2= 3,
 

// Coding
  /*
  equal_TAP1= 1,  equal_HOLD1= 2,
  less_equal_TAP1= 1,  less_equal_HOLD1= 2,
  great_equal_TAP1= 1,  great_equal_HOLD1= 2
*/

//  comma2_TAP1= 1,  comma2_HOLD1= 2,  comma2_TAP2= 3,  comma2_HOLD2= 4,
//  dot2_TAP1= 1,  dot2_HOLD1= 2,  dot2_TAP2= 3,  dot2_HOLD2= 4,
//  *_TAP1= 1,  *_HOLD1= 2,  *_TAP2= 3,  *_HOLD2= 4,

}td_state_t;

//static td_state_t td_state; 
// not needed 
typedef struct { bool is_press_action; int state; }tap;

// function to determine the current tapdance state
//General
  int cur_alttab (qk_tap_dance_state_t *state);
  int cur_copy (qk_tap_dance_state_t *state); 

//Math Type Base
  int cur_a (qk_tap_dance_state_t *state);
  int cur_b (qk_tap_dance_state_t *state);
  int cur_c (qk_tap_dance_state_t *state);
  int cur_d (qk_tap_dance_state_t *state);
  int cur_e (qk_tap_dance_state_t *state);
  int cur_f (qk_tap_dance_state_t *state);
  int cur_h (qk_tap_dance_state_t *state);
  int cur_i (qk_tap_dance_state_t *state);
  int cur_j (qk_tap_dance_state_t *state);
  int cur_k (qk_tap_dance_state_t *state);
  int cur_l (qk_tap_dance_state_t *state);
  int cur_m (qk_tap_dance_state_t *state);
  int cur_n (qk_tap_dance_state_t *state);
  int cur_o (qk_tap_dance_state_t *state);
  int cur_p (qk_tap_dance_state_t *state);
  int cur_q (qk_tap_dance_state_t *state);
  int cur_r (qk_tap_dance_state_t *state);
  int cur_s (qk_tap_dance_state_t *state);
  int cur_t (qk_tap_dance_state_t *state);
  int cur_u (qk_tap_dance_state_t *state);
  int cur_v (qk_tap_dance_state_t *state);
  int cur_w (qk_tap_dance_state_t *state);
  int cur_x (qk_tap_dance_state_t *state);
  int cur_y (qk_tap_dance_state_t *state);
  int cur_z (qk_tap_dance_state_t *state);
  int cur_comma (qk_tap_dance_state_t *state);
  int cur_dot (qk_tap_dance_state_t *state);
  int cur_equal (qk_tap_dance_state_t *state);
  int cur_great_equal (qk_tap_dance_state_t *state); 
  int cur_less_equal (qk_tap_dance_state_t *state);

//Math Type Math symboles
   int cur_QUES (qk_tap_dance_state_t *state);
   int cur_EXLM (qk_tap_dance_state_t *state);
   int cur_ASTR (qk_tap_dance_state_t *state);
   int cur_CIRC (qk_tap_dance_state_t *state);
   int cur_SCOlON (qk_tap_dance_state_t *state);
   int cur_UNDS (qk_tap_dance_state_t *state);
   int cur_MINUS (qk_tap_dance_state_t *state);
   int cur_EQUAL2 (qk_tap_dance_state_t *state);
   int cur_PLUS (qk_tap_dance_state_t *state);
   int cur_DQUO (qk_tap_dance_state_t *state);
   int cur_TILD (qk_tap_dance_state_t *state);
   int cur_PERC (qk_tap_dance_state_t *state);
   int cur_SLASH (qk_tap_dance_state_t *state);
   int cur_BSLASH (qk_tap_dance_state_t *state);
   int cur_QUOTE (qk_tap_dance_state_t *state);
   int cur_COLON (qk_tap_dance_state_t *state);

//Math Type Math symboles
   int cur_LABK (qk_tap_dance_state_t *state);
   int cur_RABK (qk_tap_dance_state_t *state);   
   int cur_LPRN (qk_tap_dance_state_t *state);   
   int cur_RPRN (qk_tap_dance_state_t *state);
   int cur_LBRACKET (qk_tap_dance_state_t *state);
   int cur_RBRACKET (qk_tap_dance_state_t *state);
   int cur_LCBR (qk_tap_dance_state_t *state);
   int cur_RCBR (qk_tap_dance_state_t *state);
   int cur_PIPE (qk_tap_dance_state_t *state);   
   
//Math Type Numbers
  int cur_n1 (qk_tap_dance_state_t *state);
  int cur_n2 (qk_tap_dance_state_t *state);
  int cur_n3 (qk_tap_dance_state_t *state);
  int cur_n4 (qk_tap_dance_state_t *state);
  int cur_n5 (qk_tap_dance_state_t *state);
  int cur_n6 (qk_tap_dance_state_t *state);
  int cur_n7 (qk_tap_dance_state_t *state);
  int cur_n8 (qk_tap_dance_state_t *state);
  int cur_n9 (qk_tap_dance_state_t *state);
  int cur_n0 (qk_tap_dance_state_t *state);

   
// Hebrew last letters   
   int cur_B (qk_tap_dance_state_t *state); 
   int cur_M (qk_tap_dance_state_t *state); 
   int cur_N (qk_tap_dance_state_t *state); 
   int cur_P (qk_tap_dance_state_t *state); 
   int cur_F (qk_tap_dance_state_t *state); 
   
//Coding
  int cur_equal (qk_tap_dance_state_t *state);
  int cur_great_equal (qk_tap_dance_state_t *state); 
  int cur_less_equal (qk_tap_dance_state_t *state);

//else
//   int cur_** (qk_tap_dance_state_t *state);



// `finished` and `reset` functions for each tapdance keycode
  void alttab_finished (qk_tap_dance_state_t *state, void *user_data);
  void alttab_reset (qk_tap_dance_state_t *state, void *user_data);
  void copy_finished (qk_tap_dance_state_t *state, void *user_data);
  void copy_reset (qk_tap_dance_state_t *state, void *user_data);

  void a_finished (qk_tap_dance_state_t *state, void *user_data);
  void a_reset (qk_tap_dance_state_t *state, void *user_data);
  void b_finished (qk_tap_dance_state_t *state, void *user_data);
  void b_reset (qk_tap_dance_state_t *state, void *user_data);
  void c_finished (qk_tap_dance_state_t *state, void *user_data);
  void c_reset (qk_tap_dance_state_t *state, void *user_data);
  void d_finished (qk_tap_dance_state_t *state, void *user_data);
  void d_reset (qk_tap_dance_state_t *state, void *user_data);
  void e_finished (qk_tap_dance_state_t *state, void *user_data);
  void e_reset (qk_tap_dance_state_t *state, void *user_data);
  void f_finished (qk_tap_dance_state_t *state, void *user_data);
  void f_reset (qk_tap_dance_state_t *state, void *user_data);
  void g_finished (qk_tap_dance_state_t *state, void *user_data);
  void g_reset (qk_tap_dance_state_t *state, void *user_data);
  void h_finished (qk_tap_dance_state_t *state, void *user_data);
  void h_reset (qk_tap_dance_state_t *state, void *user_data);
  void i_finished (qk_tap_dance_state_t *state, void *user_data);
  void i_reset (qk_tap_dance_state_t *state, void *user_data);
  void j_finished (qk_tap_dance_state_t *state, void *user_data);
  void j_reset (qk_tap_dance_state_t *state, void *user_data);
  void k_finished (qk_tap_dance_state_t *state, void *user_data);
  void k_reset (qk_tap_dance_state_t *state, void *user_data);
  void l_finished (qk_tap_dance_state_t *state, void *user_data);
  void l_reset (qk_tap_dance_state_t *state, void *user_data);
  void m_finished (qk_tap_dance_state_t *state, void *user_data);
  void m_reset (qk_tap_dance_state_t *state, void *user_data);
  void n_finished (qk_tap_dance_state_t *state, void *user_data);
  void n_reset (qk_tap_dance_state_t *state, void *user_data);
  void o_finished (qk_tap_dance_state_t *state, void *user_data);
  void o_reset (qk_tap_dance_state_t *state, void *user_data);
  void p_finished (qk_tap_dance_state_t *state, void *user_data);
  void p_reset (qk_tap_dance_state_t *state, void *user_data);
  void q_finished (qk_tap_dance_state_t *state, void *user_data);
  void q_reset (qk_tap_dance_state_t *state, void *user_data);
  void r_finished (qk_tap_dance_state_t *state, void *user_data);
  void r_reset (qk_tap_dance_state_t *state, void *user_data);
  void s_finished (qk_tap_dance_state_t *state, void *user_data);
  void s_reset (qk_tap_dance_state_t *state, void *user_data);
  void t_finished (qk_tap_dance_state_t *state, void *user_data);
  void t_reset (qk_tap_dance_state_t *state, void *user_data);
  void u_finished (qk_tap_dance_state_t *state, void *user_data);
  void u_reset (qk_tap_dance_state_t *state, void *user_data);
  void v_finished (qk_tap_dance_state_t *state, void *user_data);
  void v_reset (qk_tap_dance_state_t *state, void *user_data);
  void w_finished (qk_tap_dance_state_t *state, void *user_data);
  void w_reset (qk_tap_dance_state_t *state, void *user_data);
  void x_finished (qk_tap_dance_state_t *state, void *user_data);
  void x_reset (qk_tap_dance_state_t *state, void *user_data);
  void y_finished (qk_tap_dance_state_t *state, void *user_data);
  void y_reset (qk_tap_dance_state_t *state, void *user_data);
  void z_finished (qk_tap_dance_state_t *state, void *user_data);
  void z_reset (qk_tap_dance_state_t *state, void *user_data);
 
  void comma_finished (qk_tap_dance_state_t *state, void *user_data);
  void comma_reset (qk_tap_dance_state_t *state, void *user_data);
  void dot_finished (qk_tap_dance_state_t *state, void *user_data);
  void dot_reset (qk_tap_dance_state_t *state, void *user_data);

  
  void QUES_finished (qk_tap_dance_state_t *state, void *user_data);
  void QUES_reset (qk_tap_dance_state_t *state, void *user_data);
  void EXLM_finished (qk_tap_dance_state_t *state, void *user_data);
  void EXLM_reset (qk_tap_dance_state_t *state, void *user_data);
  void ASTR_finished (qk_tap_dance_state_t *state, void *user_data);
  void ASTR_reset (qk_tap_dance_state_t *state, void *user_data);
  void CIRC_finished (qk_tap_dance_state_t *state, void *user_data);
  void CIRC_reset (qk_tap_dance_state_t *state, void *user_data);
  void SCOLON_finished (qk_tap_dance_state_t *state, void *user_data);
  void SCOLON_reset (qk_tap_dance_state_t *state, void *user_data);
  void UNDS_finished (qk_tap_dance_state_t *state, void *user_data);
  void UNDS_reset (qk_tap_dance_state_t *state, void *user_data);
  void MINUS_finished (qk_tap_dance_state_t *state, void *user_data);
  void MINUS_reset (qk_tap_dance_state_t *state, void *user_data);
  void EQUAL2_finished (qk_tap_dance_state_t *state, void *user_data);
  void EQUAL2_reset (qk_tap_dance_state_t *state, void *user_data);
  void PLUS_finished (qk_tap_dance_state_t *state, void *user_data);
  void PLUS_reset (qk_tap_dance_state_t *state, void *user_data);
  void DQUO_finished (qk_tap_dance_state_t *state, void *user_data);
  void DQUO_reset (qk_tap_dance_state_t *state, void *user_data);
  void TILD_finished (qk_tap_dance_state_t *state, void *user_data);
  void TILD_reset (qk_tap_dance_state_t *state, void *user_data);
  void PERC_finished (qk_tap_dance_state_t *state, void *user_data);
  void PERC_reset (qk_tap_dance_state_t *state, void *user_data);
  void SLASH_finished (qk_tap_dance_state_t *state, void *user_data);
  void SLASH_reset (qk_tap_dance_state_t *state, void *user_data);
  void BSLASH_finished (qk_tap_dance_state_t *state, void *user_data);
  void BSLASH_reset (qk_tap_dance_state_t *state, void *user_data);
  void QUOTE_finished (qk_tap_dance_state_t *state, void *user_data);
  void QUOTE_reset (qk_tap_dance_state_t *state, void *user_data);
  void COLON_finished (qk_tap_dance_state_t *state, void *user_data);
  void COLON_reset (qk_tap_dance_state_t *state, void *user_data);
  
  void LABK_finished (qk_tap_dance_state_t *state, void *user_data);
  void LABK_reset (qk_tap_dance_state_t *state, void *user_data);
  void RABK_finished (qk_tap_dance_state_t *state, void *user_data);
  void RABK_reset (qk_tap_dance_state_t *state, void *user_data);
  void LPRN_finished (qk_tap_dance_state_t *state, void *user_data);
  void LPRN_reset (qk_tap_dance_state_t *state, void *user_data);
  void RPRN_finished (qk_tap_dance_state_t *state, void *user_data);
  void RPRN_reset (qk_tap_dance_state_t *state, void *user_data);
  void LBRACKET_finished (qk_tap_dance_state_t *state, void *user_data);
  void LBRACKET_reset (qk_tap_dance_state_t *state, void *user_data);
  void RBRACKET_finished (qk_tap_dance_state_t *state, void *user_data);
  void RBRACKET_reset (qk_tap_dance_state_t *state, void *user_data);
  void PIPE_finished (qk_tap_dance_state_t *state, void *user_data);
  void PIPE_reset (qk_tap_dance_state_t *state, void *user_data);

// Math Type Numbers
  void n1_finished (qk_tap_dance_state_t *state, void *user_data);
  void n1_reset (qk_tap_dance_state_t *state, void *user_data);
  void n2_finished (qk_tap_dance_state_t *state, void *user_data);
  void n2_reset (qk_tap_dance_state_t *state, void *user_data);
  void n3_finished (qk_tap_dance_state_t *state, void *user_data);
  void n3_reset (qk_tap_dance_state_t *state, void *user_data);
  void n4_finished (qk_tap_dance_state_t *state, void *user_data);
  void n4_reset (qk_tap_dance_state_t *state, void *user_data);
  void n5_finished (qk_tap_dance_state_t *state, void *user_data);
  void n5_reset (qk_tap_dance_state_t *state, void *user_data);
  void n6_finished (qk_tap_dance_state_t *state, void *user_data);
  void n6_reset (qk_tap_dance_state_t *state, void *user_data);
  void n7_finished (qk_tap_dance_state_t *state, void *user_data);
  void n7_reset (qk_tap_dance_state_t *state, void *user_data);
  void n8_finished (qk_tap_dance_state_t *state, void *user_data);
  void n8_reset (qk_tap_dance_state_t *state, void *user_data);
  void n9_finished (qk_tap_dance_state_t *state, void *user_data);
  void n9_reset (qk_tap_dance_state_t *state, void *user_data);
  void n0_finished (qk_tap_dance_state_t *state, void *user_data);
  void n0_reset (qk_tap_dance_state_t *state, void *user_data);

// Hebrew last letters  
  void B_finished (qk_tap_dance_state_t *state, void *user_data);
  void B_reset (qk_tap_dance_state_t *state, void *user_data);
  void M_finished (qk_tap_dance_state_t *state, void *user_data);
  void M_reset (qk_tap_dance_state_t *state, void *user_data);
  void N_finished (qk_tap_dance_state_t *state, void *user_data);
  void N_reset (qk_tap_dance_state_t *state, void *user_data);
  void P_finished (qk_tap_dance_state_t *state, void *user_data);
  void P_reset (qk_tap_dance_state_t *state, void *user_data);
  void F_finished (qk_tap_dance_state_t *state, void *user_data);
  void F_reset (qk_tap_dance_state_t *state, void *user_data);

// Coding
  /*
  void equal_finished (qk_tap_dance_state_t *state, void *user_data);
  void equal_reset (qk_tap_dance_state_t *state, void *user_data);
  void less_equal_finished (qk_tap_dance_state_t *state, void *user_data);
  void less_equal_reset (qk_tap_dance_state_t *state, void *user_data);
  void great_equal_finished (qk_tap_dance_state_t *state, void *user_data);
  void great_equal_reset (qk_tap_dance_state_t *state, void *user_data);
*/  

//  void *_finished (qk_tap_dance_state_t *state, void *user_data);
//  void *_reset (qk_tap_dance_state_t *state, void *user_data);



// Tap Dance Declarations Over


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    LGUI_T(KC_ESCAPE), KC_Q,         KC_W,           TD(TD_copy),    KC_PASTE,       KC_UNDO,          KC_REDO,                                        XXX,                     XXX,    LCTL(KC_L),     LCTL(KC_E),         LCTL(KC_R),     LCTL(KC_F),  KC_AUDIO_VOL_UP,
    KC_TAB,            KC_COMMA,     KC_DOT,         KC_E,           KC_R,           KC_T,             KC_HOME,                                        XXX,                     KC_Y,   KC_U,           KC_I,               KC_O,           XXX,         KC_AUDIO_VOL_DOWN,
    TD_alttab,         KC_A,         KC_S,           KC_D,           KC_F,           KC_G,                                                                                      KC_H,   KC_J,           KC_K,               KC_L,           XXX,         TO(1),
    KC_MS_WH_UP,       KC_Z,         KC_X,           KC_UP,          KC_V,           KC_B,             KC_END,                                         OSM(MOD_LCTL|MOD_LALT),  KC_N,   KC_M,           KC_P,               KC_C,           XXX,         KC_LANGUAGE,
    KC_MS_WH_DOWN,     KC_LSHIFT,    KC_LEFT,        KC_DOWN,        KC_RIGHT,                                                                                                          KC_BSPACE,      KC_DELETE,          KC_LSHIFT,      XXX,         XXX,
                                                                                                        PRINT_SCREEN,     PRINT_SCREEN2,     XXX,             TG(4),
                                                                                                                          XXX,               XXX,
                                                                                       LT(2,KC_SPACE),  LT(7,KC_ENTER),   KC_BSPACE,         OSM(MOD_LALT),   OSM(MOD_LCTL),      OSL(3)
  ),

  // Hebrew
  [1] = LAYOUT_ergodox_pretty(
    ___,   ___,        ___,        ___,    ___,         ___,        ___,        ___,     ___,    ___,       ___,          ___,   ___,         ___,
    ___,   KC_QUOTE,   KC_SLASH,   KC_E,   KC_R,        KC_Z,       ___,        ___,     XXX,    KC_K,      TD(TD_F),     XXX,   ___,         ___,
    ___,   KC_A,       KC_V,       KC_T,   KC_C,        KC_G,                            KC_J,   TD(TD_N),  KC_U,         KC_H,  ___,         TO(0),
    ___,   KC_D,       KC_S,       ___,    TD(TD_B),    TD(TD_M),   ___,        ___,     KC_Y,   TD(TD_P),  KC_COMMA,     KC_X,  ___,         ___,
    ___,   ___,        ___,        ___,    ___,                                                  ___,       ___,          ___,   LCTLP(KC_S),  ___,
                                                                   ___,  ___,   ___,  ___, 
                                                                         ___,   ___,
                                                             ___,  ___,  ___,   ___,  ___,  ___
	  ),  
	  
//Math and numbers
  [2] = LAYOUT_ergodox_pretty(
    ___,        ___,       ___,      KC_EXLM,   ___,      ___,       ___,           ___,          ___,         LCTL(KC_I),  LCTL(KC_U),   LCTL(KC_B),   ___, ___,
    ___,        ___,       ___,      KC_CIRC,   KC_DQUO,  KC_QUOTE,  KC_SCOLON,		  KC_NUM_SIGN,  ___,         KC_7,        KC_8,         KC_9,         ___, ___,
    KC_BSLASH,  KC_SLASH,  KC_MINUS, KC_EQUAL,  KC_PLUS,  KC_ASTR,                                ___,         KC_4,        KC_5,         KC_6,         ___, ___,
    KC_GRAVE,   KC_PERC,   KC_TILD,  ___,       KC_LABK,  KC_RABK,   KC_COLN,       KC_QUES,      ___,         KC_1,        KC_2,         KC_3,         ___, ___,
    ___,        ___,       ___,      ___,       ___,                                                           ___,         KC_0,         ___,          ___, ___,
                                                                       ___, ___,    ___, ___,
                                                                            ___,    ___,
                                                                  ___, ___, ___,    ___, ___, ___
  ), 
  
  
//Brackets
  [3] = LAYOUT_ergodox_pretty(   
  ___,        ___,       ___,      KC_EXLM,   ___,      ___,       ___,           ___,          ___,      LCTL(KC_I),   LCTL(KC_U),   LCTL(KC_B),    ___, ___,
  ___,        ___,       ___,      KC_CIRC,   KC_DQUO,  KC_QUOTE,  KC_SCOLON,     KC_NUM_SIGN,  KC_AMPR,  KC_LBRACKET,  KC_RBRACKET,  KC_DLR,        ___, ___,
  KC_BSLASH,  KC_SLASH,  KC_MINUS, KC_EQUAL,  KC_PLUS,  KC_ASTR,                                KC_PIPE,  KC_LPRN,      KC_RPRN,      KC_UNDS,       ___, ___,
  KC_GRAVE,   KC_PERC,   KC_TILD,  ___,       KC_LABK,  KC_RABK,   KC_COLN,       KC_QUES,      KC_AT,    KC_LCBR,      KC_RCBR,      ___,           ___, ___,
  ___,        ___,       ___,      ___,       ___,                                                        ___,          ___,          ___,           ___, ___,
                                                                     ___, ___,    ___, ___,
                                                                          ___,    ___,
                                                               ___,  ___, ___,    ___, ST_MACRO_8, ___
  ), 

  [7] = LAYOUT_ergodox_pretty(   
  ___,        ___,       ___,      KC_EXLM,   ___,      ___,       ___,            ___,    ___,  ___,         ___,         ___,           ___,    ___,
  ___,        ___,       ___,      KC_CIRC,   KC_DQUO,  KC_QUOTE,  KC_SCOLON,      ___,    ___,  ___,         KC_MS_UP,    ___,           ___,    ___,
  KC_BSLASH,  KC_SLASH,  KC_MINUS, KC_EQUAL,  KC_PLUS,  KC_ASTR,                           ___,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,   ___,    ___,
  KC_GRAVE,   KC_PERC,   KC_TILD,  ___,       KC_LABK,  KC_RABK,   KC_COLN,        ___,    ___,  ___,         ___,         ___,           ___,    ___,
  ___,        ___,       ___,      ___,       ___,                                               KC_MS_BTN2,  ___,         ___,           ___,    ___,
                                                                     ___, ___,     ___,  ___,
                                                                          ___,     ___,
                                                               ___,  ___, ___,     ___,  ST_MACRO_8,  KC_MS_BTN1
  ), 




// Math Type
// Math Type Base
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, TD(TD_q),       TD(TD_w),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,                                   KC_TRANSPARENT,                  KC_TRANSPARENT, LCTL(LALT(KC_T)), LCTL(LALT(KC_G)),  LCTL(LALT(KC_B)),   KC_TRANSPARENT,    KC_TRANSPARENT,
    KC_TRANSPARENT, TD(TD_comma),   TD(TD_dot), TD(TD_e),       TD(TD_r),       TD(Td_t),        KC_TRANSPARENT,                                   LCTL(LALT(KC_F5)),               TD(TD_y),       TD(TD_u),         TD(TD_i),          TD(TD_o),           KC_TRANSPARENT,    KC_TRANSPARENT,
    KC_TRANSPARENT, TD(TD_a),       TD(TD_s),   TD(TD_d),       TD(TD_f),       TD(TD_g),                                                                                           TD(TD_h),       TD(TD_j),         TD(TD_k),          TD(TD_l),           KC_TRANSPARENT,    KC_TRANSPARENT,
    KC_TRANSPARENT, TD(TD_z),       TD(TD_x),   KC_UP,          TD(TD_v),       TD(TD_b),        KC_TRANSPARENT,                                   OSM(MOD_LCTL|MOD_LALT),          TD(TD_n),       TD(TD_m),         TD(TD_p),          TD(TD_c),           KC_TRANSPARENT,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,    KC_DOWN,        KC_RIGHT,                                                                                                                           KC_BSPACE,        KC_DELETE,         KC_LSHIFT,          KC_TRANSPARENT,    KC_TRANSPARENT,
                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT,  KC_TRANSPARENT, 
                                                                                                                 KC_TRANSPARENT,   KC_TRANSPARENT,
                                                                             LT(5,KC_SPACE), LSFT_T(KC_ENTER),  KC_TRANSPARENT,    OSM(MOD_LALT),   OSM(MOD_LCTL),    OSL(6)
  ),

// Math Type Numbers and math symboles
// Tap dance for Symbols, hold for ctrl + symbol, double for alt + symbol
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,   TD(TD_EXLM),       KC_TRANSPARENT,    KC_TRANSPARENT,    KC_TRANSPARENT,                                 KC_TRANSPARENT,              KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,   TD(TD_CIRC),       TD(TD_DQUO),       TD(TD_QUOTE),      TD(TD_SCOLON),                                  KC_NUM_SIGN,                 KC_I,            TD(TD_n7),       TD(TD_n8),       TD(TD_n9),      KC_TRANSPARENT, KC_TRANSPARENT,
    TD(TD_BSLASH),  TD(TD_SLASH),       TD(TD_MINUS),     TD(TD_EQUAL2),     TD(TD_PLUS),       TD(TD_ASTR),                                                                                    Pi_Macro_Math,   TD(TD_n4),       TD(TD_n5),       TD(TD_n6),      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_GRAVE,       TD(TD_PERC),        TD(TD_TILD),      KC_TRANSPARENT,    TD(TD_LABK),       TD(TD_RABK),       TD(TD_COLON),                                   KC_QUES,                     Inf_Macro_Math,  TD(TD_n1),       TD(TD_n2),       TD(TD_n3),      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,   KC_TRANSPARENT,    KC_TRANSPARENT,                                                                                                                     KC_BSPACE,       TD(TD_n0),       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, OSL(6)                                                                                               
),


// Tap Dance for Backets basics advanced Math Type
// Hold for ctrl + symbol, double for alt + symbol
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,   TD(TD_EXLM),       KC_TRANSPARENT,    KC_TRANSPARENT,    KC_TRANSPARENT,                               KC_TRANSPARENT,            KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,   TD(TD_CIRC),       TD(TD_DQUO),       TD(TD_QUOTE),      TD(TD_SCOLON),                                KC_NUM_SIGN,               KC_AMPR,          TD(TD_LBRACKET),  TD(TD_RBRACKET),  KC_DLR,         KC_TRANSPARENT, KC_TRANSPARENT,
    TD(TD_BSLASH),  TD(TD_SLASH),       TD(TD_MINUS),     TD(TD_EQUAL2),     TD(TD_PLUS),       TD(TD_ASTR),                                                                                TD(TD_PIPE),      TD(TD_LPRN),      TD(TD_RPRN),      TD(TD_UNDS),    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_GRAVE,       TD(TD_PERC),        TD(TD_TILD),      KC_TRANSPARENT,    TD(TD_LABK),       TD(TD_RABK),       TD(TD_COLON),                                 KC_QUES,                   KC_AT,            TD(TD_LCBR),      TD(TD_RCBR),      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,   KC_TRANSPARENT,    KC_TRANSPARENT,                                                                                                                  KC_TRANSPARENT,   KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                               KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                               KC_TRANSPARENT,   KC_TRANSPARENT,
                                                                                               KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, ST_MACRO_9,     KC_TRANSPARENT
  ),



};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {


    case ST_MACRO_8://math type base layer on
    if (record->event.pressed) {  
      layer_on(4); 
      register_code16 (KC_LALT); register_code16 (KC_LSHIFT);clear_mods();//hebrew
      register_code16 (KC_LCTL);register_code16 (KC_LALT);register_code16 (KC_Q);clear_mods();unregister_code16 (KC_Q); //math type
    } break;

    case ST_MACRO_9://Math Type Layer off
    if (record->event.pressed) { 
      layer_off(4);      layer_off(0);
      register_code16 (KC_LALT); register_code16 (KC_LSHIFT);clear_mods();
      register_code16 (KC_LCTL);register_code16 (KC_LALT);register_code16 (KC_Q);clear_mods();unregister_code16 (KC_Q);
	  } break;
	
	case Inf_Macro_Math://Infinity on Math Type
    if (record->event.pressed) { 
      register_code16 (KC_LCTL); register_code16 (KC_F5);clear_mods(); register_code16 (KC_I);unregister_code16 (KC_F5);unregister_code16 (KC_I);
    } break;

	case Pi_Macro_Math:// Pi on  Math Type
    if (record->event.pressed) { 
      register_code16 (KC_LCTL); register_code16 (KC_F5);clear_mods(); register_code16 (KC_P);unregister_code16 (KC_F5);unregister_code16 (KC_P);
    } break;


	  // One button Language change - currently not in use
    /*
    case ST_MACRO_12:
    if (record->event.pressed) { 
      layer_off(0);layer_on(1); 
      register_code16 (KC_LALT); register_code16 (KC_LSHIFT); register_code16 (KC_NO);clear_mods(); unregister_code16 (KC_NO);
	  } break;
    // register_code16 (KC_ASOFF); unregister_code16 (KC_ASOFF);
    	

	case ST_MACRO_13:
    if (record->event.pressed) { 
      layer_off(1);layer_on(0);
      register_code16 (KC_LALT); register_code16 (KC_LSHIFT); register_code16 (KC_NO); clear_mods(); unregister_code16 (KC_NO);// Languge change
  //  register_code16 (KC_ASON); unregister_code16 (KC_ASON);
    } break;	
	**/
	
  }  return true; //end of switch
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 0:
	  autoshift_enable();
    break;	  
    case 1:
      ergodox_right_led_1_on();
	  autoshift_disable();
     break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
	  autoshift_enable();
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
	  ergodox_right_led_3_on();
      break;
    case 5:
      ergodox_right_led_1_on();
	  ergodox_right_led_3_on();
     break;
    case 6:
	  ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
	case 8 :
      ergodox_right_led_2_on();
    break;
    default:
      break;
  }
  return state;
};

// Tap dance functions
//alt tab
int cur_alttab (qk_tap_dance_state_t *state){
  if (state->count == 1)  { return alttab_TAP1; }
  if (state->count == 2)  { return alttab_TAP2; }
  else { return 10; }}

// handle the possible states for each tapdance keycode you define:
static tap alttab_state = { .is_press_action = true, .state = 0};

void alttab_finished (qk_tap_dance_state_t *state, void *user_data) {
  alttab_state.state  = cur_alttab(state);
  switch (alttab_state.state) {
    case alttab_TAP1: register_code16 (KC_LALT); register_code16 (KC_TAB); break;
    case alttab_TAP2: register_code16 (KC_LALT); register_code16 (KC_LCTL); register_code16 (KC_TAB); break;
  }}

void alttab_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (alttab_state.state) {
    case alttab_TAP1: unregister_code16 (KC_LALT); unregister_code16 (KC_TAB); break;
    case alttab_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_LCTL); unregister_code16 (KC_TAB); break; 
  } alttab_state.state = 0;}

//copy
int cur_copy (qk_tap_dance_state_t *state){
  if (state->count == 1)  { return copy_TAP1; }
  if (state->count == 2)  { return copy_TAP2; }
  else { return 10; }}

static tap copy_state = { .is_press_action = true, .state = 0};

void copy_finished (qk_tap_dance_state_t *state, void *user_data) {
  copy_state.state = cur_copy(state);
  switch (copy_state.state) {
    case copy_TAP1: register_code16 (KC_LCTL); register_code16 (KC_C); break;
    case copy_TAP2: register_code16 (KC_LCTL); register_code16 (KC_X); break;
  }}

void copy_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (copy_state.state) {
   case copy_TAP1: unregister_code16 (KC_LCTL); unregister_code16 (KC_C); break;
   case copy_TAP2: unregister_code16 (KC_LCTL); unregister_code16 (KC_X); break;
  } copy_state.state = 0; } 



//a
int cur_a (qk_tap_dance_state_t *state){
  if (state->count == 1){
    if (state->interrupted || !state->pressed) { return a_TAP1; } else { return a_HOLD1; }
  }
  if (state->count == 2){
    if (state->interrupted || !state->pressed) { return a_TAP2; } else { return a_HOLD2; }
  }
  else { return 10; }}

static tap a_state = { .is_press_action = true, .state = 0};

void a_finished (qk_tap_dance_state_t *state, void *user_data) {
  a_state.state = cur_a(state);
  switch (a_state.state) {
    case a_TAP1: register_code16 (KC_A); break;
    case a_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_A); break;
    case a_TAP2: register_code16 (KC_LALT); register_code16 (KC_A); break;
    case a_HOLD2:register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_A); break;
  }}

void a_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (a_state.state) {
    case a_TAP1: unregister_code16 (KC_A); break;
    case a_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_A); break;
    case a_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_A); break;
    case a_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_A); break;
  } a_state.state = 0; } 

//////////b
int cur_b (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return b_TAP1; } else { return b_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return b_TAP2; } else { return b_HOLD2; } }
  else { return 10; }}

static tap b_state = { .is_press_action = true, .state = 0};
void b_finished (qk_tap_dance_state_t *state, void *user_data) {
  b_state.state = cur_b(state);
  switch (b_state.state) {
    case b_TAP1: register_code16 (KC_B); break;
    case b_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_B); break;
    case b_TAP2: register_code16 (KC_LALT); register_code16 (KC_B); break;
    case b_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_B); break;}}
void b_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (b_state.state) {
    case b_TAP1: unregister_code16 (KC_B); break;
    case b_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_B); break;
    case b_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_B); break;
    case b_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_B); break;
  } b_state.state = 0; } 

//////////c
int cur_c (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return c_TAP1; } else { return c_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return c_TAP2; } else { return c_HOLD2; } }
  else { return 10; }}

static tap c_state = { .is_press_action = true, .state = 0};
void c_finished (qk_tap_dance_state_t *state, void *user_data) {
  c_state.state = cur_c(state);
  switch (c_state.state) {
    case c_TAP1: register_code16 (KC_C); break;
    case c_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_C); break;
    case c_TAP2: register_code16 (KC_LALT); register_code16 (KC_C); break;
    case c_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_C); break;}}
void c_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (c_state.state) {
    case c_TAP1: unregister_code16 (KC_C); break;
    case c_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_C); break;
    case c_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_C); break;
    case c_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_C); break;
  } c_state.state = 0; } 

//////////d
int cur_d (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return d_TAP1; } else { return d_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return d_TAP2; } else { return d_HOLD2; } }
  else { return 10; }}

static tap d_state = { .is_press_action = true, .state = 0};
void d_finished (qk_tap_dance_state_t *state, void *user_data) {
  d_state.state = cur_d(state);
  switch (d_state.state) {
    case d_TAP1: register_code16 (KC_D); break;
    case d_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_D); break;
    case d_TAP2: register_code16 (KC_LALT); register_code16 (KC_D); break;
    case d_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_D); break;}}
void d_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (d_state.state) {
    case d_TAP1: unregister_code16 (KC_D); break;
    case d_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_D); break;
    case d_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_D); break;
    case d_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_D); break;
  } d_state.state = 0; } 

//////////e
int cur_e (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return e_TAP1; } else { return e_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return e_TAP2; } else { return e_HOLD2; } }
  else { return 10; }}

static tap e_state = { .is_press_action = true, .state = 0};
void e_finished (qk_tap_dance_state_t *state, void *user_data) {
  e_state.state = cur_e(state);
  switch (e_state.state) {
    case e_TAP1: register_code16 (KC_E); break;
    case e_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_E); break;
    case e_TAP2: register_code16 (KC_LALT); register_code16 (KC_E); break;
    case e_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_E); break;}}
void e_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (e_state.state) {
    case e_TAP1: unregister_code16 (KC_E); break;
    case e_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_E); break;
    case e_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_E); break;
    case e_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_E); break;
  } e_state.state = 0; } 



//////////f
int cur_f (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return f_TAP1; } else { return f_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return f_TAP2; } else { return f_HOLD2; } }
  else { return 10; }}

static tap f_state = { .is_press_action = true, .state = 0};
void f_finished (qk_tap_dance_state_t *state, void *user_data) {
  f_state.state = cur_f(state);
  switch (f_state.state) {
    case f_TAP1: register_code16 (KC_F); break;
    case f_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_F); break;
    case f_TAP2: register_code16 (KC_LALT); register_code16 (KC_F); break;
    case f_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_F); break;}}
void f_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (f_state.state) {
    case f_TAP1: unregister_code16 (KC_F); break;
    case f_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_F); break;
    case f_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_F); break;
    case f_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_F); break;
  } f_state.state = 0; } 

//////////g
int cur_g (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return g_TAP1; } else { return g_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return g_TAP2; } else { return g_HOLD2; } }
  else { return 10; }}

static tap g_state = { .is_press_action = true, .state = 0};
void g_finished (qk_tap_dance_state_t *state, void *user_data) {
  g_state.state = cur_g(state);
  switch (g_state.state) {
    case g_TAP1: register_code16 (KC_G); break;
    case g_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_G); break;
    case g_TAP2: register_code16 (KC_LALT); register_code16 (KC_G); break;
    case g_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_G); break;}}
void g_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (g_state.state) {
    case g_TAP1: unregister_code16 (KC_G); break;
    case g_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_G); break;
    case g_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_G); break;
    case g_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_G); break;
  } g_state.state = 0; }

 //////////h
int cur_h (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return h_TAP1; } else { return h_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return h_TAP2; } else { return h_HOLD2; } }
  else { return 10; }}

static tap h_state = { .is_press_action = true, .state = 0};
void h_finished (qk_tap_dance_state_t *state, void *user_data) {
  h_state.state = cur_h(state);
  switch (h_state.state) {
    case h_TAP1: register_code16 (KC_H); break;
    case h_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_H); break;
    case h_TAP2: register_code16 (KC_LALT); register_code16 (KC_H); break;
    case h_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_H); break;}}
void h_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (h_state.state) {
    case h_TAP1: unregister_code16 (KC_H); break;
    case h_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_H); break;
    case h_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_H); break;
    case h_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_H); break;
  } h_state.state = 0; } 

//////////i
int cur_i (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return i_TAP1; } else { return i_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return i_TAP2; } else { return i_HOLD2; } }
  else { return 10; }}

static tap i_state = { .is_press_action = true, .state = 0};
void i_finished (qk_tap_dance_state_t *state, void *user_data) {
  i_state.state = cur_i(state);
  switch (i_state.state) {
    case i_TAP1: register_code16 (KC_I); break;
    case i_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_I); break;
    case i_TAP2: register_code16 (KC_LALT); register_code16 (KC_I); break;
    case i_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_I); break;}}
void i_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (i_state.state) {
    case i_TAP1: unregister_code16 (KC_I); break;
    case i_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_I); break;
    case i_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_I); break;
    case i_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_I); break;
  } i_state.state = 0; } 

//////////j
int cur_j (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return j_TAP1; } else { return j_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return j_TAP2; } else { return j_HOLD2; } }
  else { return 10; }}

static tap j_state = { .is_press_action = true, .state = 0};
void j_finished (qk_tap_dance_state_t *state, void *user_data) {
  j_state.state = cur_j(state);
  switch (j_state.state) {
    case j_TAP1: register_code16 (KC_J); break;
    case j_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_J); break;
    case j_TAP2: register_code16 (KC_LALT); register_code16 (KC_J); break;
    case j_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_J); break;}}
void j_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (j_state.state) {
    case j_TAP1: unregister_code16 (KC_J); break;
    case j_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_J); break;
    case j_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_J); break;
    case j_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_J); break;
  } j_state.state = 0; } 

//////////k
int cur_k (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return k_TAP1; } else { return k_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return k_TAP2; } else { return k_HOLD2; } }
  else { return 10; }}

static tap k_state = { .is_press_action = true, .state = 0};
void k_finished (qk_tap_dance_state_t *state, void *user_data) {
  k_state.state = cur_k(state);
  switch (k_state.state) {
    case k_TAP1: register_code16 (KC_K); break;
    case k_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_K); break;
    case k_TAP2: register_code16 (KC_LALT); register_code16 (KC_K); break;
    case k_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_K); break;}}
void k_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (k_state.state) {
    case k_TAP1: unregister_code16 (KC_K); break;
    case k_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_K); break;
    case k_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_K); break;
    case k_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_K); break;
  } k_state.state = 0; } 

//////////L
int cur_l (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return l_TAP1; } else { return l_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return l_TAP2; } else { return l_HOLD2; } }
  else { return 10; }}

static tap l_state = { .is_press_action = true, .state = 0};
void l_finished (qk_tap_dance_state_t *state, void *user_data) {
  l_state.state = cur_l(state);
  switch (l_state.state) {
    case l_TAP1: register_code16 (KC_L); break;
    case l_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_L); break;
    case l_TAP2: register_code16 (KC_LALT); register_code16 (KC_L); break;
    case l_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_L); break;}}
void l_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (l_state.state) {
    case l_TAP1: unregister_code16 (KC_L); break;
    case l_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_L); break;
    case l_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_L); break;
    case l_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_L); break;
  } l_state.state = 0; } 

//////////m
int cur_m (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return m_TAP1; } else { return m_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return m_TAP2; } else { return m_HOLD2; } }
  else { return 10; }}

static tap m_state = { .is_press_action = true, .state = 0};
void m_finished (qk_tap_dance_state_t *state, void *user_data) {
  m_state.state = cur_m(state);
  switch (m_state.state) {
    case m_TAP1: register_code16 (KC_M); break;
    case m_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_M); break;
    case m_TAP2: register_code16 (KC_LALT); register_code16 (KC_M); break;
    case m_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_M); break;}}
void m_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (m_state.state) {
    case m_TAP1: unregister_code16 (KC_M); break;
    case m_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_M); break;
    case m_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_M); break;
    case m_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_M); break;
  } m_state.state = 0; } 

//////////n
int cur_n (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return n_TAP1; } else { return n_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return n_TAP2; } else { return n_HOLD2; } }
  else { return 10; }}

static tap n_state = { .is_press_action = true, .state = 0};
void n_finished (qk_tap_dance_state_t *state, void *user_data) {
  n_state.state = cur_n(state);
  switch (n_state.state) {
    case n_TAP1: register_code16 (KC_N); break;
    case n_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_N); break;
    case n_TAP2: register_code16 (KC_LALT); register_code16 (KC_N); break;
    case n_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_N); break;}}
void n_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n_state.state) {
    case n_TAP1: unregister_code16 (KC_N); break;
    case n_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_N); break;
    case n_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_N); break;
    case n_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_N); break;
  } n_state.state = 0; } 

//////////o
int cur_o (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return o_TAP1; } else { return o_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return o_TAP2; } else { return o_HOLD2; } }
  else { return 10; }}

static tap o_state = { .is_press_action = true, .state = 0};
void o_finished (qk_tap_dance_state_t *state, void *user_data) {
  o_state.state = cur_o(state);
  switch (o_state.state) {
    case o_TAP1: register_code16 (KC_O); break;
    case o_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_O); break;
    case o_TAP2: register_code16 (KC_LALT); register_code16 (KC_O); break;
    case o_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_O); break;}}
void o_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (o_state.state) {
    case o_TAP1: unregister_code16 (KC_O); break;
    case o_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_O); break;
    case o_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_O); break;
    case o_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_O); break;
  } o_state.state = 0; } 

//////////p
int cur_p (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return p_TAP1; } else { return p_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return p_TAP2; } else { return p_HOLD2; } }
  else { return 10; }}

static tap p_state = { .is_press_action = true, .state = 0};
void p_finished (qk_tap_dance_state_t *state, void *user_data) {
  p_state.state = cur_p(state);
  switch (p_state.state) {
    case p_TAP1: register_code16 (KC_P); break;
    case p_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_P); break;
    case p_TAP2: register_code16 (KC_LALT); register_code16 (KC_P); break;
    case p_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_P); break;}}
void p_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (p_state.state) {
    case p_TAP1: unregister_code16 (KC_P); break;
    case p_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_P); break;
    case p_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_P); break;
    case p_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_P); break;
  } p_state.state = 0; } 

//////////q
int cur_q (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return q_TAP1; } else { return q_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return q_TAP2; } else { return q_HOLD2; } }
  else { return 10; }}

static tap q_state = { .is_press_action = true, .state = 0};
void q_finished (qk_tap_dance_state_t *state, void *user_data) {
  q_state.state = cur_q(state);
  switch (q_state.state) {
    case q_TAP1: register_code16 (KC_Q); break;
    case q_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_Q); break;
    case q_TAP2: register_code16 (KC_LALT); register_code16 (KC_Q); break;
    case q_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_Q); break;}}
void q_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (q_state.state) {
    case q_TAP1: unregister_code16 (KC_Q); break;
    case q_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_Q); break;
    case q_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_Q); break;
    case q_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_Q); break;
  } q_state.state = 0; } 

//////////r
int cur_r (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return r_TAP1; } else { return r_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return r_TAP2; } else { return r_HOLD2; } }
  else { return 10; }}

static tap r_state = { .is_press_action = true, .state = 0};
void r_finished (qk_tap_dance_state_t *state, void *user_data) {
  r_state.state = cur_r(state);
  switch (r_state.state) {
    case r_TAP1: register_code16 (KC_R); break;
    case r_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_R); break;
    case r_TAP2: register_code16 (KC_LALT); register_code16 (KC_R); break;
    case r_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_R); break;}}
void r_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (r_state.state) {
    case r_TAP1: unregister_code16 (KC_R); break;
    case r_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_R); break;
    case r_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_R); break;
    case r_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_R); break;
  } r_state.state = 0; } 

//////////s
int cur_s (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return s_TAP1; } else { return s_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return s_TAP2; } else { return s_HOLD2; } }
  else { return 10; }}

static tap s_state = { .is_press_action = true, .state = 0};
void s_finished (qk_tap_dance_state_t *state, void *user_data) {
  s_state.state = cur_s(state);
  switch (s_state.state) {
    case s_TAP1: register_code16 (KC_S); break;
    case s_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_S); break;
    case s_TAP2: register_code16 (KC_LALT); register_code16 (KC_S); break;
    case s_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_S); break;}}
void s_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (s_state.state) {
    case s_TAP1: unregister_code16 (KC_S); break;
    case s_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_S); break;
    case s_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_S); break;
    case s_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_S); break;
  } s_state.state = 0; } 

//////////t
int cur_t (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return t_TAP1; } else { return t_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return t_TAP2; } else { return t_HOLD2; } }
  else { return 10; }}

static tap t_state = { .is_press_action = true, .state = 0};
void t_finished (qk_tap_dance_state_t *state, void *user_data) {
  t_state.state = cur_t(state);
  switch (t_state.state) {
    case t_TAP1: register_code16 (KC_T); break;
    case t_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_T); break;
    case t_TAP2: register_code16 (KC_LALT); register_code16 (KC_T); break;
    case t_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_T); break;}}
void t_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (t_state.state) {
    case t_TAP1: unregister_code16 (KC_T); break;
    case t_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_T); break;
    case t_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_T); break;
    case t_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_T); break;
  } t_state.state = 0; } 

//////////u
int cur_u (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return u_TAP1; } else { return u_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return u_TAP2; } else { return u_HOLD2; } }
  else { return 10; }}

static tap u_state = { .is_press_action = true, .state = 0};
void u_finished (qk_tap_dance_state_t *state, void *user_data) {
  u_state.state = cur_u(state);
  switch (u_state.state) {
    case u_TAP1: register_code16 (KC_U); break;
    case u_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_U); break;
    case u_TAP2: register_code16 (KC_LALT); register_code16 (KC_U); break;
    case u_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_U); break;}}
void u_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (u_state.state) {
    case u_TAP1: unregister_code16 (KC_U); break;
    case u_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_U); break;
    case u_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_U); break;
    case u_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_U); break;
  } u_state.state = 0; } 

//////////v
		
int cur_v (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return v_TAP1; } else { return v_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return v_TAP2; } else { return v_HOLD2; } }
  else { return 10; }}

static tap v_state = { .is_press_action = true, .state = 0};
void v_finished (qk_tap_dance_state_t *state, void *user_data) {
  v_state.state = cur_v(state);
  switch (v_state.state) {
    case v_TAP1: register_code16 (KC_V); break;
    case v_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_V); break;
    case v_TAP2: register_code16 (KC_LALT); register_code16 (KC_V); break;
    case v_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_V); break;}}
void v_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (v_state.state) {
    case v_TAP1: unregister_code16 (KC_V); break;
    case v_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_V); break;
    case v_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_V); break;
    case v_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_V); break;
  } v_state.state = 0; } 


//////////w
int cur_w (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return w_TAP1; } else { return w_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return w_TAP2; } else { return w_HOLD2; } }
  else { return 10; }}

static tap w_state = { .is_press_action = true, .state = 0};
void w_finished (qk_tap_dance_state_t *state, void *user_data) {
  w_state.state = cur_w(state);
  switch (w_state.state) {
    case w_TAP1: register_code16 (KC_W); break;
    case w_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_W); break;
    case w_TAP2: register_code16 (KC_LALT); register_code16 (KC_W); break;
    case w_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_W); break;}}
void w_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (w_state.state) {
    case w_TAP1: unregister_code16 (KC_W); break;
    case w_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_W); break;
    case w_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_W); break;
    case w_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_W); break;
  } w_state.state = 0; } 


//////////x
int cur_x (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return x_TAP1; } else { return x_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return x_TAP2; } else { return x_HOLD2; } }
  else { return 10; }}

static tap x_state = { .is_press_action = true, .state = 0};
void x_finished (qk_tap_dance_state_t *state, void *user_data) {
  x_state.state = cur_x(state);
  switch (x_state.state) {
    case x_TAP1: register_code16 (KC_X); break;
    case x_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_X); break;
    case x_TAP2: register_code16 (KC_LALT); register_code16 (KC_X); break;
    case x_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_X); break;}}
void x_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (x_state.state) {
    case x_TAP1: unregister_code16 (KC_X); break;
    case x_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_X); break;
    case x_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_X); break;
    case x_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_X); break;
  } x_state.state = 0; } 


//////////y
int cur_y (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return y_TAP1; } else { return y_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return y_TAP2; } else { return y_HOLD2; } }
  else { return 10; }}

static tap y_state = { .is_press_action = true, .state = 0};
void y_finished (qk_tap_dance_state_t *state, void *user_data) {
  y_state.state = cur_y(state);
  switch (y_state.state) {
    case y_TAP1: register_code16 (KC_Y); break;
    case y_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_Y); break;
    case y_TAP2: register_code16 (KC_LALT); register_code16 (KC_Y); break;
    case y_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_Y); break;}}
void y_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (y_state.state) {
    case y_TAP1: unregister_code16 (KC_Y); break;
    case y_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_Y); break;
    case y_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_Y); break;
    case y_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_Y); break;
  } y_state.state = 0; } 


//////////z
int cur_z (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return z_TAP1; } else { return z_HOLD1; } }
  if (state->count == 2){ if (state->interrupted || !state->pressed) { return z_TAP2; } else { return z_HOLD2; } }
  else { return 10; }}

static tap z_state = { .is_press_action = true, .state = 0};
void z_finished (qk_tap_dance_state_t *state, void *user_data) {
  z_state.state = cur_z(state);
  switch (z_state.state) {
    case z_TAP1: register_code16 (KC_Z); break;
    case z_HOLD1: register_code16 (KC_LSFT); register_code16 (KC_Z); break;
    case z_TAP2: register_code16 (KC_LALT); register_code16 (KC_Z); break;
    case z_HOLD2: register_code16 (KC_LALT); register_code16 (KC_LSFT); register_code16 (KC_Z); break;}}
void z_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (z_state.state) {
    case z_TAP1: unregister_code16 (KC_Z); break;
    case z_HOLD1: unregister_code16 (KC_LSFT); unregister_code16 (KC_Z); break;
    case z_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_Z); break;
    case z_HOLD2:unregister_code16 (KC_LALT); unregister_code16 (KC_LSFT); unregister_code16 (KC_Z); break;
  } z_state.state = 0; } 


//////////comma
int cur_comma (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return comma_TAP1; } else { return comma_HOLD1; } }
  if (state->count == 2){ return comma_TAP2; }
  else { return 10; }}

static tap comma_state = { .is_press_action = true, .state = 0};
void comma_finished (qk_tap_dance_state_t *state, void *user_data) {
  comma_state.state = cur_comma(state);
  switch (comma_state.state) {
    case comma_TAP1: register_code16 (KC_COMMA); break;
    case comma_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_COMMA); break;
    case comma_TAP2: register_code16 (KC_LALT); register_code16 (KC_COMMA); break;}}
void comma_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (comma_state.state) {
    case comma_TAP1: unregister_code16 (KC_COMMA); break;
    case comma_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_COMMA); break;
    case comma_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_COMMA); break;
  } comma_state.state = 0; } 


//////////dot
int cur_dot (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return dot_TAP1; } else { return dot_HOLD1; } }
  if (state->count == 2) { return dot_TAP2; } 
  else { return 10; }}

static tap dot_state = { .is_press_action = true, .state = 0};
void dot_finished (qk_tap_dance_state_t *state, void *user_data) {
  dot_state.state = cur_dot(state);
  switch (dot_state.state) {
    case dot_TAP1: register_code16 (KC_DOT); break;
    case dot_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_DOT); break;
    case dot_TAP2: register_code16 (KC_LALT); register_code16 (KC_DOT); break;}}
void dot_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (dot_state.state) {
    case dot_TAP1: unregister_code16 (KC_DOT); break;
    case dot_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_DOT); break;
    case dot_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_DOT); break;
  } dot_state.state = 0; } 


////////////////////////////////////////////////////////////////////////////////
//MATH TYPE SYMBOLES


//////////QUES‎
int cur_QUES (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return QUES_TAP1;
	 	} 
	else {
		 return QUES_HOLD1; }
 }
  if (state->count == 2){return QUES_TAP2;}
  else { return 10; }}

static tap QUES_state = { .is_press_action = true, .state = 0};
void QUES_finished (qk_tap_dance_state_t *state, void *user_data) {
  QUES_state.state = cur_QUES(state);
  switch (QUES_state.state) {
    case QUES_TAP1: register_code16 (KC_QUES); break;
    case QUES_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_QUES); break;
    case QUES_TAP2: register_code16 (KC_LALT); register_code16 (KC_QUES); break;}}
void QUES_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (QUES_state.state) {
    case QUES_TAP1: unregister_code16 (KC_QUES); break;
    case QUES_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_QUES); break;
    case QUES_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_QUES); break;
  } QUES_state.state = 0; }  
//////////EXLM‎
int cur_EXLM (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return EXLM_TAP1;
	 	} 
	else {
		 return EXLM_HOLD1; }
 }
  if (state->count == 2){return EXLM_TAP2;}
  else { return 10; }}

static tap EXLM_state = { .is_press_action = true, .state = 0};
void EXLM_finished (qk_tap_dance_state_t *state, void *user_data) {
  EXLM_state.state = cur_EXLM(state);
  switch (EXLM_state.state) {
    case EXLM_TAP1: register_code16 (KC_EXLM); break;
    case EXLM_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_EXLM); break;
    case EXLM_TAP2: register_code16 (KC_LALT); register_code16 (KC_EXLM); break;}}
void EXLM_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (EXLM_state.state) {
    case EXLM_TAP1: unregister_code16 (KC_EXLM); break;
    case EXLM_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_EXLM); break;
    case EXLM_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_EXLM); break;
  } EXLM_state.state = 0; }  
//////////ASTR‎
int cur_ASTR (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return ASTR_TAP1;
	 	} 
	else {
		 return ASTR_HOLD1; }
 }
  if (state->count == 2){return ASTR_TAP2;}
  else { return 10; }}

static tap ASTR_state = { .is_press_action = true, .state = 0};
void ASTR_finished (qk_tap_dance_state_t *state, void *user_data) {
  ASTR_state.state = cur_ASTR(state);
  switch (ASTR_state.state) {
    case ASTR_TAP1: register_code16 (KC_ASTR); break;
    case ASTR_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_ASTR); break;
    case ASTR_TAP2: register_code16 (KC_LALT); register_code16 (KC_ASTR); break;}}
void ASTR_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (ASTR_state.state) {
    case ASTR_TAP1: unregister_code16 (KC_ASTR); break;
    case ASTR_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_ASTR); break;
    case ASTR_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_ASTR); break;
  } ASTR_state.state = 0; }   
//////////CIRC‎
int cur_CIRC (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return CIRC_TAP1;
	 	} 
	else {
		 return CIRC_HOLD1; }
 }
  if (state->count == 2){return CIRC_TAP2;}
  else { return 10; }}

static tap CIRC_state = { .is_press_action = true, .state = 0};
void CIRC_finished (qk_tap_dance_state_t *state, void *user_data) {
  CIRC_state.state = cur_CIRC(state);
  switch (CIRC_state.state) {
    case CIRC_TAP1: register_code16 (KC_CIRC); break;
    case CIRC_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_CIRC); break;
    case CIRC_TAP2: register_code16 (KC_LALT); register_code16 (KC_CIRC); break;}}
void CIRC_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (CIRC_state.state) {
    case CIRC_TAP1: unregister_code16 (KC_CIRC); break;
    case CIRC_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_CIRC); break;
    case CIRC_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_CIRC); break;
  } CIRC_state.state = 0; } 
  
//////////SCOLON‎
int cur_SCOLON (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return SCOLON_TAP1;
	 	} 
	else {
		 return SCOLON_HOLD1; }
 }
  if (state->count == 2){return SCOLON_TAP2;}
  else { return 10; }}

static tap SCOLON_state = { .is_press_action = true, .state = 0};
void SCOLON_finished (qk_tap_dance_state_t *state, void *user_data) {
  SCOLON_state.state = cur_SCOLON(state);
  switch (SCOLON_state.state) {
    case SCOLON_TAP1: register_code16 (KC_SCOLON); break;
    case SCOLON_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_SCOLON); break;
    case SCOLON_TAP2: register_code16 (KC_LALT); register_code16 (KC_SCOLON); break;}}
void SCOLON_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (SCOLON_state.state) {
    case SCOLON_TAP1: unregister_code16 (KC_SCOLON); break;
    case SCOLON_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_SCOLON); break;
    case SCOLON_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_SCOLON); break;
  } SCOLON_state.state = 0; }  
  
//////////COLON‎
int cur_COLON (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return COLON_TAP1;
	 	} 
	else {
		 return COLON_HOLD1; }
 }
  if (state->count == 2){return COLON_TAP2;}
  else { return 10; }}

static tap COLON_state = { .is_press_action = true, .state = 0};
void COLON_finished (qk_tap_dance_state_t *state, void *user_data) {
  COLON_state.state = cur_COLON(state);
  switch (COLON_state.state) {
    case COLON_TAP1: register_code16 (KC_COLON); break;
    case COLON_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_COLON); break;
    case COLON_TAP2: register_code16 (KC_LALT); register_code16 (KC_COLON); break;}}
void COLON_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (COLON_state.state) {
    case COLON_TAP1: unregister_code16 (KC_COLON); break;
    case COLON_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_COLON); break;
    case COLON_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_COLON); break;
  } COLON_state.state = 0; }    

//////////UNDS‎
int cur_UNDS (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return UNDS_TAP1;
	 	} 
	else {
		 return UNDS_HOLD1; }
 }
  if (state->count == 2){return UNDS_TAP2;}
  else { return 10; }}

static tap UNDS_state = { .is_press_action = true, .state = 0};
void UNDS_finished (qk_tap_dance_state_t *state, void *user_data) {
  UNDS_state.state = cur_UNDS(state);
  switch (UNDS_state.state) {
    case UNDS_TAP1: register_code16 (KC_UNDS); break;
    case UNDS_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_UNDS); break;
    case UNDS_TAP2: register_code16 (KC_LALT); register_code16 (KC_UNDS); break;}}
void UNDS_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (UNDS_state.state) {
    case UNDS_TAP1: unregister_code16 (KC_UNDS); break;
    case UNDS_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_UNDS); break;
    case UNDS_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_UNDS); break;
  } UNDS_state.state = 0; }    

//////////MINUS‎
int cur_MINUS (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return MINUS_TAP1;
	 	} 
	else {
		 return MINUS_HOLD1; }
 }
  if (state->count == 2){return MINUS_TAP2;}
  else { return 10; }}

static tap MINUS_state = { .is_press_action = true, .state = 0};
void MINUS_finished (qk_tap_dance_state_t *state, void *user_data) {
  MINUS_state.state = cur_MINUS(state);
  switch (MINUS_state.state) {
    case MINUS_TAP1: register_code16 (KC_MINUS); break;
    case MINUS_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_MINUS); break;
    case MINUS_TAP2: register_code16 (KC_LALT); register_code16 (KC_MINUS); break;}}
void MINUS_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (MINUS_state.state) {
    case MINUS_TAP1: unregister_code16 (KC_MINUS); break;
    case MINUS_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_MINUS); break;
    case MINUS_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_MINUS); break;
  } MINUS_state.state = 0; }    

//////////PLUS‎
int cur_PLUS (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return PLUS_TAP1;
	 	} 
	else {
		 return PLUS_HOLD1; }
 }
  if (state->count == 2){return PLUS_TAP2;}
  else { return 10; }}

static tap PLUS_state = { .is_press_action = true, .state = 0};
void PLUS_finished (qk_tap_dance_state_t *state, void *user_data) {
  PLUS_state.state = cur_PLUS(state);
  switch (PLUS_state.state) {
    case PLUS_TAP1: register_code16 (KC_PLUS); break;
    case PLUS_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_PLUS); break;
    case PLUS_TAP2: register_code16 (KC_LALT); register_code16 (KC_PLUS); break;}}
void PLUS_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (PLUS_state.state) {
    case PLUS_TAP1: unregister_code16 (KC_PLUS); break;
    case PLUS_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_PLUS); break;
    case PLUS_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_PLUS); break;
  } PLUS_state.state = 0; }   

//////////DQUO‎
int cur_DQUO (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return DQUO_TAP1;
	 	} 
	else {
		 return DQUO_HOLD1; }
 }
  if (state->count == 2){return DQUO_TAP2;}
  else { return 10; }}

static tap DQUO_state = { .is_press_action = true, .state = 0};
void DQUO_finished (qk_tap_dance_state_t *state, void *user_data) {
  DQUO_state.state = cur_DQUO(state);
  switch (DQUO_state.state) {
    case DQUO_TAP1: register_code16 (KC_DQUO); break;
    case DQUO_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_DQUO); break;
    case DQUO_TAP2: register_code16 (KC_LALT); register_code16 (KC_DQUO); break;}}
void DQUO_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (DQUO_state.state) {
    case DQUO_TAP1: unregister_code16 (KC_DQUO); break;
    case DQUO_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_DQUO); break;
    case DQUO_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_DQUO); break;
  } DQUO_state.state = 0; }    
//////////TILD‎
int cur_TILD (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return TILD_TAP1;
	 	} 
	else {
		 return TILD_HOLD1; }
 }
  if (state->count == 2){return TILD_TAP2;}
  else { return 10; }}

static tap TILD_state = { .is_press_action = true, .state = 0};
void TILD_finished (qk_tap_dance_state_t *state, void *user_data) {
  TILD_state.state = cur_TILD(state);
  switch (TILD_state.state) {
    case TILD_TAP1: register_code16 (KC_TILD); break;
    case TILD_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_TILD); break;
    case TILD_TAP2: register_code16 (KC_LALT); register_code16 (KC_TILD); break;}}
void TILD_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (TILD_state.state) {
    case TILD_TAP1: unregister_code16 (KC_TILD); break;
    case TILD_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_TILD); break;
    case TILD_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_TILD); break;
  } TILD_state.state = 0; }      
//////////PERC‎
int cur_PERC (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return PERC_TAP1;
	 	} 
	else {
		 return PERC_HOLD1; }
 }
  if (state->count == 2){return PERC_TAP2;}
  else { return 10; }}

static tap PERC_state = { .is_press_action = true, .state = 0};
void PERC_finished (qk_tap_dance_state_t *state, void *user_data) {
  PERC_state.state = cur_PERC(state);
  switch (PERC_state.state) {
    case PERC_TAP1: register_code16 (KC_PERC); break;
    case PERC_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_PERC); break;
    case PERC_TAP2: register_code16 (KC_LALT); register_code16 (KC_PERC); break;}}
void PERC_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (PERC_state.state) {
    case PERC_TAP1: unregister_code16 (KC_PERC); break;
    case PERC_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_PERC); break;
    case PERC_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_PERC); break;
  } PERC_state.state = 0; }      
  
//////////SLASH‎
int cur_SLASH (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return SLASH_TAP1;
	 	} 
	else {
		 return SLASH_HOLD1; }
 }
  if (state->count == 2){return SLASH_TAP2;}
  else { return 10; }}

static tap SLASH_state = { .is_press_action = true, .state = 0};
void SLASH_finished (qk_tap_dance_state_t *state, void *user_data) {
  SLASH_state.state = cur_SLASH(state);
  switch (SLASH_state.state) {
    case SLASH_TAP1: register_code16 (KC_SLASH); break;
    case SLASH_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_SLASH); break;
    case SLASH_TAP2: register_code16 (KC_LALT); register_code16 (KC_SLASH); break;}}
void SLASH_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (SLASH_state.state) {
    case SLASH_TAP1: unregister_code16 (KC_SLASH); break;
    case SLASH_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_SLASH); break;
    case SLASH_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_SLASH); break;
  } SLASH_state.state = 0; }        
//////////BSLASH‎
int cur_BSLASH (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return BSLASH_TAP1;
	 	} 
	else {
		 return BSLASH_HOLD1; }
 }
  if (state->count == 2){return BSLASH_TAP2;}
  else { return 10; }}

static tap BSLASH_state = { .is_press_action = true, .state = 0};
void BSLASH_finished (qk_tap_dance_state_t *state, void *user_data) {
  BSLASH_state.state = cur_BSLASH(state);
  switch (BSLASH_state.state) {
    case BSLASH_TAP1: register_code16 (KC_BSLASH); break;
    case BSLASH_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_BSLASH); break;
    case BSLASH_TAP2: register_code16 (KC_LALT); register_code16 (KC_BSLASH); break;}}
void BSLASH_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (BSLASH_state.state) {
    case BSLASH_TAP1: unregister_code16 (KC_BSLASH); break;
    case BSLASH_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_BSLASH); break;
    case BSLASH_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_BSLASH); break;
  } BSLASH_state.state = 0; }        
//////////QUOTE‎
int cur_QUOTE (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return QUOTE_TAP1;
	 	} 
	else {
		 return QUOTE_HOLD1; }
 }
  if (state->count == 2){return QUOTE_TAP2;}
  else { return 10; }}

static tap QUOTE_state = { .is_press_action = true, .state = 0};
void QUOTE_finished (qk_tap_dance_state_t *state, void *user_data) {
  QUOTE_state.state = cur_QUOTE(state);
  switch (QUOTE_state.state) {
    case QUOTE_TAP1: register_code16 (KC_QUOTE); break;
    case QUOTE_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_QUOTE); break;
    case QUOTE_TAP2: register_code16 (KC_LALT); register_code16 (KC_QUOTE); break;}}
void QUOTE_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (QUOTE_state.state) {
    case QUOTE_TAP1: unregister_code16 (KC_QUOTE); break;
    case QUOTE_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_QUOTE); break;
    case QUOTE_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_QUOTE); break;
  } QUOTE_state.state = 0; }  

//////////EQUAL2‎
int cur_EQUAL2 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return EQUAL2_TAP1;
	 	} 
	else {
		 return EQUAL2_HOLD1; }
 }
  if (state->count == 2){return EQUAL2_TAP2;}
  else { return 10; }}

static tap EQUAL2_state = { .is_press_action = true, .state = 0};
void EQUAL2_finished (qk_tap_dance_state_t *state, void *user_data) {
  EQUAL2_state.state = cur_EQUAL2(state);
  switch (EQUAL2_state.state) {
    case EQUAL2_TAP1: register_code16 (KC_EQUAL); break;
    case EQUAL2_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_EQUAL); break;
    case EQUAL2_TAP2: register_code16 (KC_LALT); register_code16 (KC_EQUAL); break;}}
void EQUAL2_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (EQUAL2_state.state) {
    case EQUAL2_TAP1: unregister_code16 (KC_EQUAL); break;
    case EQUAL2_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_EQUAL); break;
    case EQUAL2_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_EQUAL); break;
  } EQUAL2_state.state = 0; }   

////////////////////////////////////////////////////////////////////////////////
//MATH TYPE BRACKETS
//////////LABK
int cur_LABK (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return LABK_TAP1;
	 	} 
	else {
		 return LABK_HOLD1; }
 }
  if (state->count == 2){return LABK_TAP2;}
  else { return 10; }}

static tap LABK_state = { .is_press_action = true, .state = 0};
void LABK_finished (qk_tap_dance_state_t *state, void *user_data) {
  LABK_state.state = cur_LABK(state);
  switch (LABK_state.state) {
    case LABK_TAP1: register_code16 (KC_LABK); break;
    case LABK_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_LABK); break;
    case LABK_TAP2: register_code16 (KC_LALT); register_code16 (KC_LABK); break;}}
void LABK_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (LABK_state.state) {
    case LABK_TAP1: unregister_code16 (KC_LABK); break;
    case LABK_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_LABK); break;
    case LABK_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_LABK); break;
  } LABK_state.state = 0; } 
//////////RABK‎
int cur_RABK (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return RABK_TAP1;
	 	} 
	else {
		 return RABK_HOLD1; }
 }
  if (state->count == 2){return RABK_TAP2;}
  else { return 10; }}

static tap RABK_state = { .is_press_action = true, .state = 0};
void RABK_finished (qk_tap_dance_state_t *state, void *user_data) {
  RABK_state.state = cur_RABK(state);
  switch (RABK_state.state) {
    case RABK_TAP1: register_code16 (KC_RABK); break;
    case RABK_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_RABK); break;
    case RABK_TAP2: register_code16 (KC_LALT); register_code16 (KC_RABK); break;}}
void RABK_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (RABK_state.state) {
    case RABK_TAP1: unregister_code16 (KC_RABK); break;
    case RABK_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_RABK); break;
    case RABK_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_RABK); break;
  } RABK_state.state = 0; }  
  
  
  //////////LPRN‎
int cur_LPRN (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return LPRN_TAP1;
	 	} 
	else {
		 return LPRN_HOLD1; }
 }
  if (state->count == 2){return LPRN_TAP2;}
  else { return 10; }}

static tap LPRN_state = { .is_press_action = true, .state = 0};
void LPRN_finished (qk_tap_dance_state_t *state, void *user_data) {
  LPRN_state.state = cur_LPRN(state);
  switch (LPRN_state.state) {
    case LPRN_TAP1: register_code16 (KC_LPRN); break;
    case LPRN_HOLD1: register_code16 (KC_LCTL);  register_code16 (KC_LPRN); break;
    case LPRN_TAP2: register_code16 (KC_LALT); register_code16 (KC_LPRN); break;}}
void LPRN_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (LPRN_state.state) {
    case LPRN_TAP1: unregister_code16 (KC_LPRN); break;
    case LPRN_HOLD1: unregister_code16 (KC_LCTL);  unregister_code16 (KC_LPRN); break;
    case LPRN_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_LPRN); break;
  } LPRN_state.state = 0; }
  
  
  //////////RPRN‎
int cur_RPRN (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return RPRN_TAP1;
	 	} 
	else {
		 return RPRN_HOLD1; }
 }
  if (state->count == 2){return RPRN_TAP2;}
  else { return 10; }}

static tap RPRN_state = { .is_press_action = true, .state = 0};
void RPRN_finished (qk_tap_dance_state_t *state, void *user_data) {
  RPRN_state.state = cur_RPRN(state);
  switch (RPRN_state.state) {
    case RPRN_TAP1: register_code16 (KC_RPRN); break;
    case RPRN_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_F6);unregister_code16 (KC_LCTL); register_code16 (KC_RPRN); break;
    case RPRN_TAP2: register_code16 (KC_LALT); register_code16 (KC_RPRN); break;}}
void RPRN_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (RPRN_state.state) {
    case RPRN_TAP1: unregister_code16 (KC_RPRN); break;
    case RPRN_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_F6); unregister_code16 (KC_RPRN); break;
    case RPRN_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_RPRN); break;
  } RPRN_state.state = 0; }
  
  
//////////LBRACKET‎
int cur_LBRACKET (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return LBRACKET_TAP1;
	 	} 
	else {
		 return LBRACKET_HOLD1; }
 }
  if (state->count == 2){return LBRACKET_TAP2;}
  else { return 10; }}

static tap LBRACKET_state = { .is_press_action = true, .state = 0};
void LBRACKET_finished (qk_tap_dance_state_t *state, void *user_data) {
  LBRACKET_state.state = cur_LBRACKET(state);
  switch (LBRACKET_state.state) {
    case LBRACKET_TAP1: register_code16 (KC_LBRACKET); break;
    case LBRACKET_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_LBRACKET); break;
    case LBRACKET_TAP2: register_code16 (KC_LALT); register_code16 (KC_LBRACKET); break;}}
void LBRACKET_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (LBRACKET_state.state) {
    case LBRACKET_TAP1: unregister_code16 (KC_LBRACKET); break;
    case LBRACKET_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_LBRACKET); break;
    case LBRACKET_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_LBRACKET); break;
  } LBRACKET_state.state = 0; }
//////////RBRACKET‎
int cur_RBRACKET (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return RBRACKET_TAP1;
	 	} 
	else {
		 return RBRACKET_HOLD1; }
 }
  if (state->count == 2){return RBRACKET_TAP2;}
  else { return 10; }}

static tap RBRACKET_state = { .is_press_action = true, .state = 0};
void RBRACKET_finished (qk_tap_dance_state_t *state, void *user_data) {
  RBRACKET_state.state = cur_RBRACKET(state);
  switch (RBRACKET_state.state) {
    case RBRACKET_TAP1: register_code16 (KC_RBRACKET); break;
    case RBRACKET_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_RBRACKET); break;
    case RBRACKET_TAP2: register_code16 (KC_LALT); register_code16 (KC_RBRACKET); break;}}
void RBRACKET_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (RBRACKET_state.state) {
    case RBRACKET_TAP1: unregister_code16 (KC_RBRACKET); break;
    case RBRACKET_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_RBRACKET); break;
    case RBRACKET_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_RBRACKET); break;
  } RBRACKET_state.state = 0; }  
  //////////LCBR‎
int cur_LCBR (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return LCBR_TAP1;
	 	} 
	else {
		 return LCBR_HOLD1; }
 }
  if (state->count == 2){return LCBR_TAP2;}
  else { return 10; }}

static tap LCBR_state = { .is_press_action = true, .state = 0};
void LCBR_finished (qk_tap_dance_state_t *state, void *user_data) {
  LCBR_state.state = cur_LCBR(state);
  switch (LCBR_state.state) {
    case LCBR_TAP1: register_code16 (KC_LCBR); break;
    case LCBR_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_LCBR); break;
    case LCBR_TAP2: register_code16 (KC_LALT); register_code16 (KC_LCBR); break;}}
void LCBR_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (LCBR_state.state) {
    case LCBR_TAP1: unregister_code16 (KC_LCBR); break;
    case LCBR_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_LCBR); break;
    case LCBR_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_LCBR); break;
  } LCBR_state.state = 0; }  
  //////////RCBR‎
int cur_RCBR (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return RCBR_TAP1;
	 	} 
	else {
		 return RCBR_HOLD1; }
 }
  if (state->count == 2){return RCBR_TAP2;}
  else { return 10; }}

static tap RCBR_state = { .is_press_action = true, .state = 0};
void RCBR_finished (qk_tap_dance_state_t *state, void *user_data) {
  RCBR_state.state = cur_RCBR(state);
  switch (RCBR_state.state) {
    case RCBR_TAP1: register_code16 (KC_RCBR); break;
    case RCBR_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_RCBR); break;
    case RCBR_TAP2: register_code16 (KC_LALT); register_code16 (KC_RCBR); break;}}
void RCBR_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (RCBR_state.state) {
    case RCBR_TAP1: unregister_code16 (KC_RCBR); break;
    case RCBR_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_RCBR); break;
    case RCBR_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_RCBR); break;
  } RCBR_state.state = 0; }  
  //////////PIPE‎
int cur_PIPE (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return PIPE_TAP1;
	 	} 
	else {
		 return PIPE_HOLD1; }
 }
  if (state->count == 2){return PIPE_TAP2;}
  else { return 10; }}

static tap PIPE_state = { .is_press_action = true, .state = 0};
void PIPE_finished (qk_tap_dance_state_t *state, void *user_data) {
  PIPE_state.state = cur_PIPE(state);
  switch (PIPE_state.state) {
    case PIPE_TAP1: register_code16 (KC_PIPE); break;
    case PIPE_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_PIPE); break;
    case PIPE_TAP2: register_code16 (KC_LALT); register_code16 (KC_PIPE); break;}}
void PIPE_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (PIPE_state.state) {
    case PIPE_TAP1: unregister_code16 (KC_PIPE); break;
    case PIPE_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_PIPE); break;
    case PIPE_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_PIPE); break;
  } PIPE_state.state = 0; }  

////////////////////////////////////////////////////////////////////////////////
// Math Type Numbers
//////////n0
int cur_n0 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n0_TAP1;
	 	} 
	else {
		 return n0_HOLD1; }
 }
  if (state->count == 2){return n0_TAP2;}
  else { return 10; }}

static tap n0_state = { .is_press_action = true, .state = 0};
void n0_finished (qk_tap_dance_state_t *state, void *user_data) {
  n0_state.state = cur_n0(state);
  switch (n0_state.state) {
    case n0_TAP1: register_code16 (KC_0); break;
    case n0_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_0); break;
    case n0_TAP2: register_code16 (KC_LALT); register_code16 (KC_0); break;}}
void n0_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n0_state.state) {
    case n0_TAP1: unregister_code16 (KC_0); break;
    case n0_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_0); break;
    case n0_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_0); break;
  } n0_state.state = 0; }  
  
//////////n1
int cur_n1 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n1_TAP1;
	 	} 
	else {
		 return n1_HOLD1; }
 }
  if (state->count == 2){return n1_TAP2;}
  else { return 10; }}

static tap n1_state = { .is_press_action = true, .state = 0};
void n1_finished (qk_tap_dance_state_t *state, void *user_data) {
  n1_state.state = cur_n1(state);
  switch (n1_state.state) {
    case n1_TAP1: register_code16 (KC_1); break;
    case n1_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_1); break;
    case n1_TAP2: register_code16 (KC_LALT); register_code16 (KC_1); break;}}
void n1_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n1_state.state) {
    case n1_TAP1: unregister_code16 (KC_1); break;
    case n1_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_1); break;
    case n1_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_1); break;
  } n1_state.state = 0; }  

//////////n2
int cur_n2 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n2_TAP1;
	 	} 
	else {
		 return n2_HOLD1; }
 }
  if (state->count == 2){return n2_TAP2;}
  else { return 10; }}

static tap n2_state = { .is_press_action = true, .state = 0};
void n2_finished (qk_tap_dance_state_t *state, void *user_data) {
  n2_state.state = cur_n2(state);
  switch (n2_state.state) {
    case n2_TAP1: register_code16 (KC_2); break;
    case n2_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_2); break;
    case n2_TAP2: register_code16 (KC_LALT); register_code16 (KC_2); break;}}
void n2_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n2_state.state) {
    case n2_TAP1: unregister_code16 (KC_2); break;
    case n2_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_2); break;
    case n2_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_2); break;
  } n2_state.state = 0; }  
  //////////n3
int cur_n3 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n3_TAP1;
	 	} 
	else {
		 return n3_HOLD1; }
 }
  if (state->count == 2){return n3_TAP2;}
  else { return 10; }}

static tap n3_state = { .is_press_action = true, .state = 0};
void n3_finished (qk_tap_dance_state_t *state, void *user_data) {
  n3_state.state = cur_n3(state);
  switch (n3_state.state) {
    case n3_TAP1: register_code16 (KC_3); break;
    case n3_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_3); break;
    case n3_TAP2: register_code16 (KC_LALT); register_code16 (KC_3); break;}}
void n3_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n3_state.state) {
    case n3_TAP1: unregister_code16 (KC_3); break;
    case n3_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_3); break;
    case n3_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_3); break;
  } n3_state.state = 0; }  
  //////////n4
int cur_n4 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n4_TAP1;
	 	} 
	else {
		 return n4_HOLD1; }
 }
  if (state->count == 2){return n4_TAP2;}
  else { return 10; }}

static tap n4_state = { .is_press_action = true, .state = 0};
void n4_finished (qk_tap_dance_state_t *state, void *user_data) {
  n4_state.state = cur_n4(state);
  switch (n4_state.state) {
    case n4_TAP1: register_code16 (KC_4); break;
    case n4_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_4); break;
    case n4_TAP2: register_code16 (KC_LALT); register_code16 (KC_4); break;}}
void n4_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n4_state.state) {
    case n4_TAP1: unregister_code16 (KC_4); break;
    case n4_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_4); break;
    case n4_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_4); break;
  } n4_state.state = 0; }  
  //////////n5
int cur_n5 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n5_TAP1;
	 	} 
	else {
		 return n5_HOLD1; }
 }
  if (state->count == 2){return n5_TAP2;}
  else { return 10; }}

static tap n5_state = { .is_press_action = true, .state = 0};
void n5_finished (qk_tap_dance_state_t *state, void *user_data) {
  n5_state.state = cur_n5(state);
  switch (n5_state.state) {
    case n5_TAP1: register_code16 (KC_5); break;
    case n5_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_5); break;
    case n5_TAP2: register_code16 (KC_LALT); register_code16 (KC_5); break;}}
void n5_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n5_state.state) {
    case n5_TAP1: unregister_code16 (KC_5); break;
    case n5_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_5); break;
    case n5_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_5); break;
  } n5_state.state = 0; }  
  //////////n6
int cur_n6 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n6_TAP1;
	 	} 
	else {
		 return n6_HOLD1; }
 }
  if (state->count == 2){return n6_TAP2;}
  else { return 10; }}

static tap n6_state = { .is_press_action = true, .state = 0};
void n6_finished (qk_tap_dance_state_t *state, void *user_data) {
  n6_state.state = cur_n6(state);
  switch (n6_state.state) {
    case n6_TAP1: register_code16 (KC_6); break;
    case n6_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_6); break;
    case n6_TAP2: register_code16 (KC_LALT); register_code16 (KC_6); break;}}
void n6_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n6_state.state) {
    case n6_TAP1: unregister_code16 (KC_6); break;
    case n6_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_6); break;
    case n6_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_6); break;
  } n6_state.state = 0; }  
  //////////n7
int cur_n7 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n7_TAP1;
	 	} 
	else {
		 return n7_HOLD1; }
 }
  if (state->count == 2){return n7_TAP2;}
  else { return 10; }}

static tap n7_state = { .is_press_action = true, .state = 0};
void n7_finished (qk_tap_dance_state_t *state, void *user_data) {
  n7_state.state = cur_n7(state);
  switch (n7_state.state) {
    case n7_TAP1: register_code16 (KC_7); break;
    case n7_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_7); break;
    case n7_TAP2: register_code16 (KC_LALT); register_code16 (KC_7); break;}}
void n7_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n7_state.state) {
    case n7_TAP1: unregister_code16 (KC_7); break;
    case n7_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_7); break;
    case n7_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_7); break;
  } n7_state.state = 0; }  
  //////////n8
int cur_n8 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n8_TAP1;
	 	} 
	else {
		 return n8_HOLD1; }
 }
  if (state->count == 2){return n8_TAP2;}
  else { return 10; }}

static tap n8_state = { .is_press_action = true, .state = 0};
void n8_finished (qk_tap_dance_state_t *state, void *user_data) {
  n8_state.state = cur_n8(state);
  switch (n8_state.state) {
    case n8_TAP1: register_code16 (KC_8); break;
    case n8_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_8); break;
    case n8_TAP2: register_code16 (KC_LALT); register_code16 (KC_8); break;}}
void n8_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n8_state.state) {
    case n8_TAP1: unregister_code16 (KC_8); break;
    case n8_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_8); break;
    case n8_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_8); break;
  } n8_state.state = 0; }  
  //////////n9
int cur_n9 (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return n9_TAP1;
	 	} 
	else {
		 return n9_HOLD1; }
 }
  if (state->count == 2){return n9_TAP2;}
  else { return 10; }}

static tap n9_state = { .is_press_action = true, .state = 0};
void n9_finished (qk_tap_dance_state_t *state, void *user_data) {
  n9_state.state = cur_n9(state);
  switch (n9_state.state) {
    case n9_TAP1: register_code16 (KC_9); break;
    case n9_HOLD1: register_code16 (KC_LCTL); register_code16 (KC_9); break;
    case n9_TAP2: register_code16 (KC_LALT); register_code16 (KC_9); break;}}
void n9_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (n9_state.state) {
    case n9_TAP1: unregister_code16 (KC_9); break;
    case n9_HOLD1: unregister_code16 (KC_LCTL); unregister_code16 (KC_9); break;
    case n9_TAP2: unregister_code16 (KC_LALT); unregister_code16 (KC_9); break;
  } n9_state.state = 0; }  
////////////////////////////////////////////////////////////////////////////////
// Hebrew last letters
//////////B
int cur_B (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return B_TAP1;} 
	else { return B_HOLD1; }
  } else { return 10; }}

static tap B_state = { .is_press_action = true, .state = 0};
void B_finished (qk_tap_dance_state_t *state, void *user_data) {
  B_state.state = cur_B(state);
  switch (B_state.state) {
    case B_TAP1: register_code16 (KC_B); break;
    case B_HOLD1: register_code16 (KC_I); break;}}
void B_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (B_state.state) {
    case B_TAP1: unregister_code16 (KC_B); break;
    case B_HOLD1: unregister_code16 (KC_I); break;
  } B_state.state = 0; }  
//////////M
int cur_M (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return M_TAP1;} 
	else { return M_HOLD1; }
  } else { return 10; }}

static tap M_state = { .is_press_action = true, .state = 0};
void M_finished (qk_tap_dance_state_t *state, void *user_data) {
  M_state.state = cur_M(state);
  switch (M_state.state) {
    case M_TAP1: register_code16 (KC_M); break;
    case M_HOLD1: register_code16 (KC_DOT); break;}}
void M_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (M_state.state) {
    case M_TAP1: unregister_code16 (KC_M); break;
    case M_HOLD1: unregister_code16 (KC_DOT); break;
  } M_state.state = 0; }  
//////////N
int cur_N (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return N_TAP1;} 
	else { return N_HOLD1; }
  } else { return 10; }}

static tap N_state = { .is_press_action = true, .state = 0};
void N_finished (qk_tap_dance_state_t *state, void *user_data) {
  N_state.state = cur_N(state);
  switch (N_state.state) {
    case N_TAP1: register_code16 (KC_N); break;
    case N_HOLD1: register_code16 (KC_O); break;}}
void N_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (N_state.state) {
    case N_TAP1: unregister_code16 (KC_N); break;
    case N_HOLD1: unregister_code16 (KC_O); break;
  } N_state.state = 0; } 
//////////P
int cur_P (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return P_TAP1;} 
	else { return P_HOLD1; }
  } else { return 10; }}

static tap P_state = { .is_press_action = true, .state = 0};
void P_finished (qk_tap_dance_state_t *state, void *user_data) {
  P_state.state = cur_P(state);
  switch (P_state.state) {
    case P_TAP1: register_code16 (KC_P); break;
    case P_HOLD1: register_code16 (KC_SCOLON); break;}}
void P_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (P_state.state) {
    case P_TAP1: unregister_code16 (KC_P); break;
    case P_HOLD1: unregister_code16 (KC_SCOLON); break;
  } P_state.state = 0; }   
//////////F
int cur_F (qk_tap_dance_state_t *state){
  if (state->count == 1){
	if (state->interrupted || !state->pressed) { 
		return F_TAP1;} 
	else { return F_HOLD1; }
  } else { return 10; }}

static tap F_state = { .is_press_action = true, .state = 0};
void F_finished (qk_tap_dance_state_t *state, void *user_data) {
  F_state.state = cur_F(state);
  switch (F_state.state) {
    case F_TAP1: register_code16 (KC_F); break;
    case F_HOLD1: register_code16 (KC_L); break;}}
void F_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (F_state.state) {
    case F_TAP1: unregister_code16 (KC_F); break;
    case F_HOLD1: unregister_code16 (KC_L); break;
  } F_state.state = 0; } 


////////////////////////////////////////////////////////////////////////////////
//CODING
//////////equal
/*
int cur_equal (qk_tap_dance_state_t *state){
  if (state->count == 1){ if (state->interrupted || !state->pressed) { return equal_TAP1; } else { return equal_HOLD1; } }
  else { return 10; }}

static tap equal_state = { .is_press_action = true, .state = 0};
void equal_finished (qk_tap_dance_state_t *state, void *user_data) {
  equal_state.state = cur_equal(state);
  switch (equal_state.state) {
    case equal_TAP1: register_code16 (KC_EQUAL); break;
    case equal_HOLD1: SEND_STRING(SS_LSFT(SS_TAP(X_1)) SS_DELAY(50) SS_TAP(X_EQUAL)); break;}}

void equal_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (equal_state.state) {
    case equal_TAP1: unregister_code16 (KC_EQUAL); break;
  } equal_state.state = 0; } 

////////// less equal
int cur_less_equal (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return less_equal_TAP1; } else { return less_equal_HOLD1; } }
  else { return 10; }}

static tap less_equal_state = { .is_press_action = true, .state = 0};
void less_equal_finished (qk_tap_dance_state_t *state, void *user_data) {
  less_equal_state.state = cur_less_equal(state);
  switch (less_equal_state.state) {
    case less_equal_TAP1: register_code16 (KC_LABK); break;
    case less_equal_HOLD1:SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(50) SS_TAP(X_EQUAL));break;}}

void less_equal_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (less_equal_state.state) {
    case less_equal_TAP1: unregister_code16 (KC_LABK); break;
  } less_equal_state.state = 0; } 

////////// great equal
int cur_great_equal (qk_tap_dance_state_t *state){
  if (state->count == 1){if (state->interrupted || !state->pressed) { return great_equal_TAP1; } else { return great_equal_HOLD1; } }
  else { return 10; }}

static tap great_equal_state = { .is_press_action = true, .state = 0};
void great_equal_finished (qk_tap_dance_state_t *state, void *user_data) {
  great_equal_state.state = cur_great_equal(state);
  switch (great_equal_state.state) {
    case great_equal_TAP1: register_code16 (KC_RABK); break;
    case great_equal_HOLD1:SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(50) SS_TAP(X_EQUAL));break;}}

void great_equal_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (great_equal_state.state) {
    case great_equal_TAP1: unregister_code16 (KC_RABK); break;
  } great_equal_state.state = 0; } 
*/


//All tap dance functions would go here. Only showing this one.

  qk_tap_dance_action_t tap_dance_actions[] ={
    [TD_alttab] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, alttab_finished, alttab_reset, 200)  
    ,[TD_copy] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, copy_finished, copy_reset, 150)

    ,[TD_a] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, a_finished, a_reset, 200)
    ,[TD_b] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, b_finished, b_reset, 200)
    ,[TD_c] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, c_finished, c_reset, 200)
    ,[TD_d] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, d_finished, d_reset, 200)
    ,[TD_e] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, e_finished, e_reset, 200)
    ,[TD_f] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, f_finished, f_reset, 200)
    ,[TD_g] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, g_finished, g_reset, 200)
    ,[TD_h] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, h_finished, h_reset, 200)
    ,[TD_i] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, i_finished, i_reset, 200)
    ,[TD_j] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, j_finished, j_reset, 200)
    ,[TD_k] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, k_finished, k_reset, 200)
    ,[TD_l] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, l_finished, l_reset, 200)
    ,[TD_m] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, m_finished, m_reset, 200)
    ,[TD_n] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n_finished, n_reset, 200)
    ,[TD_o] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, o_finished, o_reset, 200)
    ,[TD_p] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, p_finished, p_reset, 200)
    ,[TD_q] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, q_finished, q_reset, 200)
    ,[TD_r] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, r_finished, r_reset, 200)
    ,[TD_s] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, s_finished, s_reset, 200)
    ,[TD_t] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, t_finished, t_reset, 200)
    ,[TD_u] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, u_finished, u_reset, 200)
    ,[TD_v] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, v_finished, v_reset, 200)
    ,[TD_w] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, w_finished, w_reset, 200)
    ,[TD_x] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, x_finished, x_reset, 200)
    ,[TD_y] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, y_finished, y_reset, 200)
    ,[TD_z] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, z_finished, z_reset, 200)

    ,[TD_comma] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, comma_finished, comma_reset, 200)
    ,[TD_dot] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, dot_finished, dot_reset, 200)

	,[TD_EQUAL2] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, EQUAL2_finished, EQUAL2_reset, 200)	
	,[TD_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, QUOTE_finished, QUOTE_reset, 200)	
	,[TD_BSLASH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, BSLASH_finished, BSLASH_reset, 200)	
	,[TD_SLASH] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, SLASH_finished, SLASH_reset, 200)	
	,[TD_PERC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, PERC_finished, PERC_reset, 200)	
	,[TD_TILD] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, TILD_finished, TILD_reset, 200)		
	,[TD_DQUO] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, DQUO_finished, DQUO_reset, 200)		
	,[TD_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, PLUS_finished, PLUS_reset, 200)		
	,[TD_MINUS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, MINUS_finished, MINUS_reset, 200)	
	,[TD_UNDS] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, UNDS_finished, UNDS_reset, 200)
	,[TD_COLON] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, COLON_finished, COLON_reset, 200)
	,[TD_SCOLON] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, SCOLON_finished, SCOLON_reset, 200)
  ,[TD_QUES] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, QUES_finished, QUES_reset, 200)
  ,[TD_EXLM] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, EXLM_finished, EXLM_reset, 200)
  ,[TD_ASTR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, ASTR_finished, ASTR_reset, 200)
	,[TD_CIRC] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, CIRC_finished, CIRC_reset, 200)
	
	,[TD_B] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, B_finished, B_reset)
    ,[TD_N] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, N_finished, N_reset)
    ,[TD_M] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, M_finished, M_reset)
    ,[TD_F] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, F_finished, F_reset)
    ,[TD_P] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, P_finished, P_reset)
	
    ,[TD_LABK] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, LABK_finished, LABK_reset, 200)
    ,[TD_RABK] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, RABK_finished, RABK_reset, 200)
	,[TD_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, LPRN_finished, LPRN_reset, 200)
    ,[TD_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, RPRN_finished, RPRN_reset, 200)
    ,[TD_LBRACKET] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, LBRACKET_finished, LBRACKET_reset, 200)
    ,[TD_RBRACKET] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, RBRACKET_finished, RBRACKET_reset, 200)
    ,[TD_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, LCBR_finished, LCBR_reset, 200)
	,[TD_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, RCBR_finished, RCBR_reset, 200)
    ,[TD_PIPE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, PIPE_finished, PIPE_reset, 200)
  /*
    ,[TD_equal] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, equal_finished, equal_reset, 200)
    ,[TD_less_equal] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, less_equal_finished, less_equal_reset, 200)
    ,[TD_great_equal] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, great_equal_finished, great_equal_reset, 200)
*/
    ,[TD_n0] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n0_finished, n0_reset, 200)
	,[TD_n1] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n1_finished, n1_reset, 200)
	,[TD_n2] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n2_finished, n2_reset, 200)
	,[TD_n3] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n3_finished, n3_reset, 200)
	,[TD_n4] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n4_finished, n4_reset, 200)
	,[TD_n5] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n5_finished, n5_reset, 200)
	,[TD_n6] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n6_finished, n6_reset, 200)
	,[TD_n7] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n7_finished, n7_reset, 200)
	,[TD_n8] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n8_finished, n8_reset, 200)
	,[TD_n9] = ACTION_TAP_DANCE_FN_ADVANCED_TIME (NULL, n9_finished, n9_reset, 200)
  };

//   ,[TD_*] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, *_finished, *_reset)



























