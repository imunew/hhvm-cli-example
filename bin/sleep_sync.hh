<?hh

function sleep_one_second()
{
  echo '[Start] '. __FUNCTION__. PHP_EOL;
  usleep(1000 * 1000);
  echo '[End] '. __FUNCTION__. PHP_EOL;
}

function main($count)
{
  for ($i = 0; $i < $count; $i++) {
    sleep_one_second();
  }
}

main(5);
