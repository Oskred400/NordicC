/* Header Files */

#include "app_timer.h"

#include "boards.h"

#include "nrf_802154.h"

#include "nrf_delay.h"

#include "nrf_log.h"

#include "nrf_log_ctrl.h"

#include "nrf_log_default_backends.h"

#include <stdbool.h>

#include <stddef.h>

#include <stdio.h>

#include <stdlib.h>

/* end header files */

/* global variables */

#define MAX_MESSAGE_SIZE 16

#define CHANNEL 11

static volatile bool m_tx_in_progress;

static volatile bool m_tx_done;

int next_slot();

void timer_handler();
//void timer_handler_rcv();

static void create_timers();
//static void create_timers_rcv();

APP_TIMER_DEF(timer_id);
//APP_TIMER_DEF(timer_id_rcv);

#define CHANNEL 11

// static uint8_t m_message[MAX_MESSAGE_SIZE];

//static volatile uint32_t rx_counter;

int slot = -1;

int schedule[] = {0, 1, 2, 3, -1};

int l = 5;

int id = MYNODEID;

static volatile uint32_t rx_a;
static volatile uint32_t rx_b;
static volatile uint32_t rx_c;
static volatile uint32_t rx_d;

static volatile uint32_t tx_count;

//copy all elements into unit array: tx_count, rx_a, rx_b, rx_c, rx_d

static volatile uint32_t packet[5];



int main(int argc, char *argv[]) {

  (void)argc;

  (void)argv;

  // Change these values for each node
  uint8_t extended_address[] = {0x26, 0x37, 0x47, 0x57, 0x67, 0x87, 0x97, 0x09};
  // Change this for each node
  uint8_t short_address[] = {0xcd, 0x2e};

  uint8_t pan_id[] = {0x04, 0x08};



  // initialize logging

  NRF_LOG_INIT(NULL);

  NRF_LOG_DEFAULT_BACKENDS_INIT();



  // init stages

  bsp_board_init(BSP_INIT_LEDS);

  //bsp_board_led_invert(0);

  nrf_802154_init();

  nrf_802154_short_address_set(short_address);

  nrf_802154_extended_address_set(extended_address);

  nrf_802154_pan_id_set(pan_id);

  nrf_802154_promiscuous_set(true);

  nrf_802154_channel_set(CHANNEL);

  //nrf_802154_receive();

  app_timer_init();
  tx_count=0;
  rx_a = 0;
  rx_b = 0;
  rx_c = 0;
  rx_d = 0;
/*
  packet[0] = tx_count;
  packet[1] = rx_a;
  packet[2] = rx_b;
  packet[3] = rx_c;
  packet[4] = rx_d;


*/

  // BUG: you should start the timer only on the first node

  // which you do below

  //create_timers();



	
  // check for ID

  if (id == 0) {

	// start timer that ticks every 100 ms
	  create_timers();
    uint8_t message[MAX_MESSAGE_SIZE];
	
  	for (uint32_t i = 0; i < MAX_MESSAGE_SIZE; i++) {
    	message[i] = i;
  	}
    //bsp_board_led_invert(0);
    m_tx_in_progress = nrf_802154_transmit_raw(message, false);
    if (m_tx_in_progress) {
      bsp_board_led_invert(0);
    }
    
    uint32_t err_code;
    err_code = app_timer_start(timer_id, APP_TIMER_TICKS(100), NULL);
    APP_ERROR_CHECK(err_code);
    slot=0;
  }
/*
  if(schedule[slot%l] == id  )
  {
    //start transmission

    bsp_board_led_invert(0);

     m_tx_in_progress = nrf_802154_transmit_raw(message, false);

     if (m_tx_in_progress) {

       bsp_board_led_invert(0);

     }


  }*/
	else{
//	NRF_LOG_INFO("ENTERING RECEIVE MODE");
//	NRF_LOG_FLUSH();
	nrf_802154_receive();
	//create_timers_rcv();
	//uint32_t err_code;
	//err_code = app_timer_start(timer_id_rcv, APP_TIMER_TICKS(100), NULL);
	//APP_ERROR_CHECK(err_code);
	}


	


//  while (1) {

//  }



return 0;

}



void timer_handler(void *p_context) { next_slot(); }

//void timer_handler_rcv(void *p_context) { nrf_802154_receive();}



static void create_timers() {

  uint32_t err_code;

  err_code = app_timer_create(&timer_id, APP_TIMER_MODE_REPEATED, timer_handler);

  APP_ERROR_CHECK(err_code);

}

//static void create_timers_rcv(){
//	uint32_t err_code;
//	err_code =
//		app_timer_create(&timer_id_rcv, APP_TIMER_MODE_REPEATED, timer_handler_rcv);
//		APP_ERROR_CHECK(err_code);
//}




// function next slot for timeout



int next_slot() {

  
//	NRF_LOG_INFO("TRANSMITTER");
//	NRF_LOG_FLUSH();
	//slot++;
	bsp_board_led_invert(1);
  
  
  //message[1] = 0x41;

  //message[2] = 0x98;

//	NRF_LOG_INFO("LEVEL 2");
//	NRF_LOG_FLUSH();

  

 if (slot < 0)
	{
    return 0;
  }

	else {
   if (schedule[slot % l] == id) {
     uint8_t message[MAX_MESSAGE_SIZE];
     for (uint32_t i = 0; i < MAX_MESSAGE_SIZE; i++) {
       message[i] = i;
     }
     message[0] = 15;
     switch(id){
       case 0: message[1] = 0x01; 
         break;
       case 1: message[1] = 0x02;
         break;
       case 2: message[1] = 0x03;
         break;
       case 3: message[1] = 0x04;
         break;
       default: message[1] = 0x10;
         break;
     }
     m_tx_in_progress = false;
     m_tx_done = false;
     //bsp_board_led_invert(0);
      m_tx_in_progress = nrf_802154_transmit_raw(message, false);
      if (m_tx_in_progress) {
        bsp_board_led_invert(0);
      }
    tx_count++;
    //NRF_LOG_INFO("%s", nrf_log_push("Transmission ended"));
    //NRF_LOG_FLUSH();
    //free(message);
    }
	}

    if(slot%l==4){
      if(slot==499){/*

        char str[sizeof(tx_count)*6];

        sprintf(str, "%u,%u,%u,%u,%u,%u", tx_count, rx_a, rx_b, rx_c, rx_d);

        NRF_LOG_INFO("%s", nrf_log_push(str));

        NRF_LOG_FLUSH();*/

        NRF_LOG_INFO("%d,%d,%d,%d,%d", tx_count, rx_a, rx_b, rx_c, rx_d);
        NRF_LOG_FLUSH();

        tx_count=0;
        rx_a=0;
        rx_b=0;
        rx_c=0;
        rx_d=0;
        slot=-1;
      }
    uint32_t err_code;
    err_code = app_timer_start(timer_id, APP_TIMER_TICKS(100), NULL);
    APP_ERROR_CHECK(err_code);
    }


	slot++;


	//NRF_LOG_INFO("Transmission Ended");
	//NRF_LOG_FLUSH();
	return slot;

}



// received_raw()




void nrf_802154_received_raw(uint8_t *p_data, int8_t power, uint8_t lqi) {

  (void)power;

  (void)lqi;
//	NRF_LOG_INFO("Received Packet");
//	NRF_LOG_FLUSH();

  if(id!=0 && slot==-1){
    	bsp_board_led_invert(2);
	   create_timers();
    	uint32_t err_code;
    	err_code = app_timer_start(timer_id, APP_TIMER_TICKS(100), NULL);
    	APP_ERROR_CHECK(err_code);
  	  slot = 0;
    }


  else {
    uint8_t r_message[MAX_MESSAGE_SIZE];
    uint8_t length = 16;
    bsp_board_led_invert(2);
    //bsp_board_led_invert(1);
    memcpy(r_message, p_data, length);
    switch(r_message[1]) {
       case 0x01:
        //NRF_LOG_INFO("%s", nrf_log_push("Tx received from A"));
        //NRF_LOG_FLUSH();
	      rx_a++;
        break;
      case 0x02:
        //NRF_LOG_INFO("%s", nrf_log_push("Tx received from B"));
        //NRF_LOG_FLUSH();
        rx_b++;
        break;
      case 0x03:
        //NRF_LOG_INFO("%s", nrf_log_push("Tx received from C"));
        //NRF_LOG_FLUSH();
        rx_c++;
        break;
      case 0x04:
        //NRF_LOG_INFO("%s", nrf_log_push("Tx received from D"));
        //NRF_LOG_FLUSH();
        rx_d++;
        break;
      default: break;
    }
    //free(r_message);
  }


nrf_802154_buffer_free_raw(p_data);

}




void nrf_802154_transmitted(const uint8_t *p_frame, uint8_t *p_ack, uint8_t length, int8_t power, int8_t lqi) {

  (void)p_frame;

  (void)length;

  (void)power;

  (void)lqi;

	//NRF_LOG_INFO("Entered transmitted function");
//	NRF_LOG_FLUSH();

  m_tx_done = true;

  bsp_board_led_invert(2);



  if (p_ack != NULL) {

    // nrf_802154_buffer_free(p_ack);

    nrf_802154_buffer_free_raw(p_ack);

  }

}
