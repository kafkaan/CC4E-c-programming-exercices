char *month_name(int n) /* return name of n-th month */
{
  static char *name[] = {
    "illegal month",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };

  return((n < 1 || n > 12) ? name[0] : name[n]);
}