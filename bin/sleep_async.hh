<?hh

async function sleep_one_second(): Awaitable<void>
{
  echo '[Start] '. __FUNCTION__. PHP_EOL;
  await \HH\Asio\usleep(1000 * 1000);
  echo '[End] '. __FUNCTION__. PHP_EOL;
}

async function main($count): Awaitable<void>
{
  $awaitables = [];
  for ($i = 0; $i < $count; $i++) {
    $awaitables[] = sleep_one_second();
  }

  echo '[Start] await'. PHP_EOL;
  await \HH\Asio\v($awaitables);
  echo '[End] await'. PHP_EOL;
}

\HH\Asio\join(main(5));
