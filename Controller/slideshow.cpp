#pragma once

namespace uk { 

    express_tcp_t slideshow() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();

            cli.write( regex::format( _STRING_(

            )));

        });

        return app;
    }

}