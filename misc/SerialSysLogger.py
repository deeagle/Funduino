#!/usr/bin/python3


import serial
import logging
import logging.handlers

'''
    Logger enumeration
'''


class Logger:
    file = 0
    syslog = 1


LOG_TAG = 'ARDUINO_SERIAL'
SERIAL_PORT = '/dev/ttyACM0'
SERIAL_BAUD = 9600
LOG_DEVICE = '/dev/log'
LOG_FILE = '/tmp/arduino.log'
LOGGER_NAME = 'ARDUINO_LOG'


def get_logger(log_sys):
    logger = logging.getLogger(LOGGER_NAME)
    logger.setLevel(logging.DEBUG)

    if Logger.file == log_sys:
        handler = logging.handlers.RotatingFileHandler(LOG_FILE, maxBytes=(1048576 * 5), backupCount=7)
        logging.basicConfig(filename=LOG_FILE,
                            filemode='a',
                            format='%(asctime)s,%(msecs)d %(name)s %(levelname)s %(message)s',
                            datefmt='%H:%M:%S',
                            level=logging.DEBUG)
    elif Logger.syslog == log_sys:
        handler = logging.handlers.SysLogHandler(address=LOG_DEVICE)
        formatter_string = '[{0}] [%(process)d]: %(levelname)s %(message)s'.format(LOG_TAG)
        # handler.setFormatter(logging.Formatter('%(pathname)s [%(process)d]: %(levelname)s %(message)s'))
        handler.setFormatter(logging.Formatter(formatter_string))
    else:
        raise ValueError('Value is not supported')

    logger.addHandler(handler)

    return logger


if __name__ == '__main__':
    ser = serial.Serial(SERIAL_PORT, SERIAL_BAUD)
    LOG = get_logger(Logger.file)

    while True:
        ser_data = ser.readline()

        # decode the byte string from the arduino to a unicode string
        unicode_from_byte_string = ser_data.decode('unicode_escape')
        # print(ser_data)
        LOG.debug(unicode_from_byte_string)
