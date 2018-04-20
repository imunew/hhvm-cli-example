<?hh

require __DIR__."/../vendor/autoload.php";

use Aws\S3\S3Client;
use GuzzleHttp\Promise as Promise;

async function uploadFile($s3, $filename): Awaitable<Promise\Promise>
{
  echo "[start uploadFile] {$filename}". PHP_EOL;

  $promise = $s3->putObjectAsync([
    'Bucket' => getenv('AWS_S3_BUCKET'),
    'Key' => basename($filename),
    'SourceFile' => $filename
  ]);

  echo "[end uploadFile] {$filename}". PHP_EOL;

  return $promise;
}

async function upload(): Awaitable<void>
{
  $s3 = new S3Client([
    'region' => 'ap-northeast-1',
    'version' => 'latest',
    'profile' => 'default'
  ]);

  $imagesDir = realpath(__DIR__.'/../var/images');

  $awaitables = [];
  foreach (glob($imagesDir.'/*.png') as $filename) {
    $awaitables[] = uploadFile($s3, $filename);
  }

  $promises = await \HH\Asio\v($awaitables);
  $promiseAll = Promise\all($promises);
  $promiseAll->wait();
}

$startTime = microtime(true);
upload();
$endTime = microtime(true);

echo '[Finished] in '. ($endTime - $startTime). ' seconds.'. PHP_EOL;
