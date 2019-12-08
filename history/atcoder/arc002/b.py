import datetime

y,m,d = map(int, input().split('/'))
ans = datetime.date(y,m,d)

while(y % (m*d) != 0):
    ans  = ans + datetime.timedelta(days=1)
    y = ans.year
    m = ans.month
    d = ans.day

print(str(ans).replace('-', '/'))
