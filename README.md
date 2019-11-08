# SE_TPFinal
TP Final de Sistemas Embebidos

## Hardware

Comprar:

    Mics
    Módulos BT
    Módulos ADC
    Ficha de audio
    Regulador
    Pila
    Opamps (MC33202)
    RC

Entrada:

    Conexión BT - ADC, transmisión de datos
    Conexión BT - BT, delay
    Conexión BT - EDU-CIAA
    Conexión filtro anti-aliasing - ADC
    Conexión micrófono - filtro anti-aliasing, ganancia y bias
    Alimentación placa externa
    *PCB placa externa*
    Conexión ADC - EDU-CIAA
    *PCB placa principal, poncho*

Salida:

    Conexión filtro reconstructor - EDU-CIAA, ganancia y bias
    Conexión ficha de audio - filtro reconstructor
    *DAC externo*
    *PCB placa principal, poncho*

*Opt:*

    PCB
    DAC externo
        Adaptar filtro de reconstrucción
        Adaptar software

## Software

    Diagrama de estados, LEDS de validación
    Comunicación ADC
    Comunicación BT
    Escritura por DAC
    *Comunicación DAC externo*
    Punto flotante

## Algoritmos

    Generación de ruido blanco
    Identificación del sistema
    Prueba de convergencia
    Filtro adaptativo
    *distintos filtros*
    Algoritmo de dithering
    *Libraries de fxLMS*

## Interfaz

    Inicio y apagado
    Elección de parámetros
    Verificación de convergencia
    *envío de datos por BT*
    *elección de filtros*
    *ploteo de FFT*

## Testeo

    Funcionamiento del camino captura de señal - conversión A/D - conversión D/A - reproducción de sonido
    Cancelación de ruido en modo FF
    Cancelación de ruido en modo FB
    Modificación de parámetros de los filtros digitales para mejorar la eficacia del cancelador
    Limitaciones del sistema en cuanto a las frecuencias del ruido a cancelar y la zona en donde cancela ruido

## Informe

    Diagrama de instalación y conexión de micrófonos y parlantes.
    Indicaciones para la modificación de parámetros en tiempo real.
    Informe final que incluye un diagrama esquemático del funcionamiento del dispositivo, y los resultados y análisis de las pruebas realizadas.
