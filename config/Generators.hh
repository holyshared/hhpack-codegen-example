<?hh //strict

namespace HHPack\Example\Generators;

use HHPack\Codegen\Cli\{ DefinedGenerator };
use HHPack\Codegen\Contract\{ GeneratorProvider };
use HHPack\Codegen\HackUnit\{ TestClassGenerator };
use HHPack\Codegen\Project\{ PackageClassGenerator };
use function HHPack\Codegen\Cli\{ namespace_of, define_generator };

final class Generators implements GeneratorProvider {
  // Your package namespace
  const string PACKAGE_NAMESPACE = 'HHPack\Example';
  const string PACKAGE_TEST_NAMESPACE = 'HHPack\Example\Test';

  public function generators(): Iterator<DefinedGenerator> {
    // Link package namespace to generator
    yield define_generator('package:class', 'generate class file for package')
      ->mapTo(
        namespace_of(static::PACKAGE_NAMESPACE, 'src')->
          map(PackageClassGenerator::class)
      );

    // Link package test namespace to generator
    yield define_generator('package:testclass', 'generate test class file for package')
      ->mapTo(
        namespace_of(static::PACKAGE_TEST_NAMESPACE, 'test')->
          map(TestClassGenerator::class)
      );
  }
}
