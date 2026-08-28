class Solution:

  def lexPalindromicPermutation(self, s: str, target: str) -> str:
    n = len(s)
    count = [0] * 26
    for c in s:
      count[ord(c) - ord('a')] += 1

    center = ''
    for i in range(26):
      if count[i] % 2 == 1:
        if center:
          return ''
        center = chr(ord('a') + i)
        count[i] -= 1

    half = n // 2

    for i in range(half):
      count[ord(target[i]) - ord('a')] -= 2

    def check(f):
      return all(x >= 0 for x in f)

    if check(count):
      head = target[:half]
      candidate = head + center + head[::-1]
      if candidate > target:
        return candidate

    for i in range(half - 1, -1, -1):
      w = target[i]
      count[ord(w) - ord('a')] += 2

      if not check(count):
        continue

      for j in range(ord(w) - ord('a') + 1, 26):
        if count[j] >= 2:
          count[j] -= 2

          head = list(target[:i]) + [chr(ord('a') + j)]

          remaining = half - len(head)

          for k in range(26):
            cnt = min(count[k] // 2, remaining)
            head.extend([chr(ord('a') + k)] * cnt)
            remaining -= cnt
            count[k] -= cnt * 2

          head_str = ''.join(head)
          return head_str + center + head_str[::-1]

    return ''