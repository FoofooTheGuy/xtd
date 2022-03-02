#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  static void main() {
    application::run(form1());
  }
  
  form1() {
    text("Form with CMake assembly info");
    controls().push_back_range({company, product, version, company_name, product_name, product_version});
    client_size({350, 105});
    
    company.text("Company name");
    company.location({10, 10});
    company.text_align(content_alignment::middle_left);
    
    product.text("Product name");
    product.location({10, 40});
    product.text_align(content_alignment::middle_left);
    
    version.text("Product version");
    version.location({10, 70});
    version.text_align(content_alignment::middle_left);
    
    company_name.text(application::company_name());
    company_name.border_style(forms::border_style::bevel_inset);
    company_name.location({120, 10});
    company_name.text_align(content_alignment::middle_left);
    company_name.width(220);
    
    product_name.text(application::product_name());
    product_name.border_style(forms::border_style::bevel_inset);
    product_name.location({120, 40});
    product_name.text_align(content_alignment::middle_left);
    product_name.width(220);
    
    product_version.text(application::product_version());
    product_version.border_style(forms::border_style::bevel_inset);
    product_version.location({120, 70});
    product_version.text_align(content_alignment::middle_left);
    product_version.width(220);
  }
  
private:
  label company;
  label product;
  label version;
  
  label company_name;
  label product_name;
  label product_version;
};

startup_(form1);
