class Solution:
    def calc_time(self, position: int, speed: int, target: int) -> float:
        return abs(target - position) / speed

    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        if not position:
            return 0

        pos_speed, times, stk = [], [], []
        fleets = len(position)
        pos_speed = list(zip(position, speed)) # because zip returns some weird object, cast to list of tuples (ending at len of shortert list)
        pos_speed.sort(key=lambda x: x[0], reverse=True) # could just call .sort(reverse=True) and it sorts by first element (position)

        # push first time
        stk.append(self.calc_time(pos_speed[0][0], pos_speed[0][1], target))
        
        for pos, spd in pos_speed[1:]: #start at idx 1 what would happen if pos_speed is of size 1?
            t = self.calc_time(pos, spd, target)

            if stk[-1] >= t:
                fleets -= 1
            else:
                stk.append(t)

        return fleets





"""

12

position     8     5     1
speed        2     9      1
time         2     0.7    11     


time to reach target with given speed and starting/ending pos:

t = dispalcement / speed
  = abs(target - position) / speed

mayhaps sort by position in decreasing order
keep track of position and speed so order is not lost when sorting

push first car (time) onto stack

    for t in times:
        if t < stk[-1]:
            # two cars became one fleet
        else:
            # two seperate fleets


        pos_speed = []
        for pos, spd in zip(position, speed):
            pos_speed.append((pos, speed))

        INSTEAD USE ZIP


"""