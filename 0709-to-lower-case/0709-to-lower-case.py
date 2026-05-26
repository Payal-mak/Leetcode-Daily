class Solution:
    def toLowerCase(self, s: str) -> str:
        res = ""

        for ch in s:
            if ch.isupper():
                res += ch.lower()
            else:
                res += ch

        return res