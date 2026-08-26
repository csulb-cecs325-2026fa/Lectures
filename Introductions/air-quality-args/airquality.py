def main():
    pm25 = float(input("Please enter the amount of PM2.5, in ug/m^3: "))

    if 0 <= pm25 <= 12.0:
        cLow, cHigh = 0.0, 12.0
        iLow, iHigh = 0, 50
    elif 12.0 < pm25 <= 35.4:
        cLow, cHigh = 12.1, 35.4
        iLow, iHigh = 51, 100
    elif 35.4 < pm25 <= 55.4:
        cLow, cHigh = 35.5, 55.4
        iLow, iHigh = 101, 150
    elif 55.4 < pm25 <= 150.4:
        cLow, cHigh = 55.5, 150.4
        iLow, iHigh = 151, 200
    elif 150.4 < pm25 <= 250.4:
        cLow, cHigh = 150.5, 250.4
        iLow, iHigh = 201, 300
    elif 250.4 < pm25 <= 350.4:
        cLow, cHigh = 250.5, 350.4
        iLow, iHigh = 301, 400
    else:
        cLow, cHigh = 350.5, 500.4
        iLow, iHigh = 401, 500

    aqi = (iHigh - iLow) / (cHigh - cLow) * (pm25 - cLow) + iLow
    print(f"AQI for PM2.5: {aqi}")
    
    if aqi <= 50:
        print("Air Quality: Good")
    elif aqi <= 100:
        print("Air Quality: Moderate")
    elif aqi <= 150:
        print("Air Quality: Unhealthy for Sensitive Groups")
    elif aqi <= 200:
        print("Air Quality: Unhealthy")
    elif aqi <= 300:
        print("Air Quality: Very Unhealthy")
    else:
        print("Air Quality: Hazardous")

if __name__ == "__main__":
    main()

