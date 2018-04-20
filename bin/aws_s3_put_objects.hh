<?hh

require __DIR__."/../vendor/autoload.php";

use Aws\S3\S3Client;

function uploadFile($s3, $filename)
{
  echo "[start uploadFile] {$filename}". PHP_EOL;

  $s3->putObject([
    'Bucket' => getenv('AWS_S3_BUCKET'),
    'Key' => basename($filename),
    'SourceFile' => $filename
  ]);

  echo "[end uploadFile] {$filename}". PHP_EOL;
}

function upload()
{
  $s3 = new S3Client([
    'region' => 'ap-northeast-1',
    'version' => 'latest',
    'profile' => 'default'
  ]);

  $imagesDir = realpath(__DIR__.'/../var/images');

  foreach (glob($imagesDir.'/*.png') as $filename) {
    uploadFile($s3, $filename);
  }
}

$startTime = microtime(true);
upload();
$endTime = microtime(true);

echo '[Finished] in '. ($endTime - $startTime). ' seconds.'. PHP_EOL;
