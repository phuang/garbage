import bisect
import datetime

ORDINAL = datetime.date(2009, 1, 1).toordinal() << 4

class Calendar:
    def __init__(self):
        self.__tasks = []
        self.__timeset = 0

    def insert_task(self, task):
        ordinal = (task.start_date.toordinal() << 4) - ORDINAL
        work = task.work
        workbits = ((1 << work) - 1) << ordinal

        if (self.__timeset & workbits) != 0:
            return False

        self.__timeset |= workbits
        return True

    def find_empty(self, date, work):
        oridinal = (date.toordinal() << 4) - ORDINAL
        workbits = (1 << work) - 1

