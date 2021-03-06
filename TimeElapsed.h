/**
 * @file timeElapsed.h
 * 
 * @author Daniel Calvo
 *
 */
#ifndef TIMEELAPSED_H
#define TIMEELAPSED_H

/**
  * Longitud que debe tener el buffer de texto para que pueda recibir
  * la cadena con el tiempo transcurrido.
  */
#define MAX_LEN_TIMEELAPSED 13

enum TypeOfTexts { t_LONG, t_SECONDS, t_MINUTES, t_HOURS, t_DAYS };

/**
 * @brief Clase para el control del tiempo transcurrido.
 *
 * Contiene los miembros y funciones necesarias para un control del tiempo transcurrido.
 * 
 */
class TimeElapsed {
    byte _seconds;				///< Segundos transcurridos
    byte _minutes;				///< Minutos transcurridos
    byte _hours;				///< Horas transcurridas
    byte _days;					///< Dias transcurridos
    unsigned long lastUpdate;			///< Cuando se ha producido la última actualización del tiempo
    void update(unsigned int nTicks);		///< Permite actualizar el contador de tiempo
  public:
    TimeElapsed(byte days = 0, byte hours = 0, byte minutes = 0, byte seconds = 0); 	///< Constructor
    
    byte getSeconds();					///< Función getter para los segundos
    byte getMinutes();					///< Función getter para los minutos
    byte getHours();					///< Función getter para las horas
    byte getDays();					///< Función getter para los días
    void getTimeElapsed(char *buffer, int nSizeBuffer, TypeOfTexts format = t_LONG); ///< Permite obtener en un array de char el tiempo transcurrido
    void loopTimeElapsed();             		///< Función para actualizar los contadores internos
    void reset();                       		///< Reinicializa los contadores internos a 0 y empieza la cuenta
};

#endif
