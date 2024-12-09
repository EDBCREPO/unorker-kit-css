#pragma once

namespace uk { 

    express_tcp_t index() {
        auto app = express::http::add();

        app.ALL([=]( express_http_t cli ){ cli.send();
            cli.write( _STRING_(
            
                .uk-index-top    { z-index: 1000; }
            
                .uk-index-normal { z-index:    0; }
            
                .uk-index-bottom { z-index:-1000; }
            
            )); 

        });

        return app;
    }

}