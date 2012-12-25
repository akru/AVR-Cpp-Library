#include <atmega8/analog_digital_converter.h>
#include <avr/io.h>
#include <avr/interrupt.h>

AnalogDigitalConverter::AnalogDigitalConverter()
  : mode( 1 )
{
  ADCSRA |= ( 1 << ADPS1 ) | ( 1 << ADPS2 );
  ADCSRA |= ( 1 << ADEN );
}

int AnalogDigitalConverter::convert( char channel )
{
  char high, low;
  cli();
  ADMUX = ( mode << 6 ) | ( channel & 0x07 );
  ADCSRA |= ( 1 << ADSC );
  while ( bit_is_set( ADCSRA, ADSC ) );
  low = ADCL;
  high = ADCH;
  sei();
  return ( high << 8 ) | low;
}
