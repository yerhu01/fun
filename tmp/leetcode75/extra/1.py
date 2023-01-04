# Integer to Roman

class Solution:
    def intToRoman(self, num: int) -> str:
        # 123 = C XX III
        # 268 = CC LX VIII
        # 999 = CM XC IX
        # 444 = CD XL IV
        romans = (('', "I","II","III","IV","V","VI","VII","VIII","IX"),
                  ('', "X","XX","XXX","XL","L","LX","LXX","LXXX","XC"),
                  ('', "C","CC","CCC","CD","D","DC","DCC","DCCC","CM"),
                  ('', "M","MM","MMM"))
        ret = []
        place = 0
        while num:
            i = num % 10
            ret.append(romans[place][i])
            num //= 10
            place += 1
        return ''.join(reversed(ret))
