# Error handing
def Divide(Number):
    try:
        return (42/Number)
    except ZeroDivisionError:
        return ('Division between zero no defined')
print(Divide(0))
